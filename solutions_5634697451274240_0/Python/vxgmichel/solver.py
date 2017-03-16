"""Provide a solver decorator for programming contests."""

# Imports
import sys
import argparse
from timeit import default_timer as time
from contextlib import contextmanager
from multiprocessing import Pool

# Compatibility
try:
    from itertools import imap as map
except ImportError:
    pass


def get_command_line_kwargs(name, args=None):
    """Get keyword arguments from the command line."""
    desc = ("Solve the {} problem using a given input file. "
            "By default, an '.out' file is written "
            "with the same name as the input file. "
            "The results are also printed along with "
            "a timing of the whole execution. "
            "Multiprocessing is used by default.")
    parser = argparse.ArgumentParser(prog=name,
                                     description=desc.format(name))
    parser.add_argument('input_file', metavar='INPUT',
                        type=str,
                        help='file to read')
    parser.add_argument('--output', '-o', metavar='OUT',
                        type=str, dest='output_file', default=True,
                        help='write a specific file')
    parser.add_argument('--no-result', '-nr',
                        dest='display', action='store_false', default=True,
                        help='do not print the results')
    parser.add_argument('--no-timing', '-nt',
                        dest='timing', action='store_false', default=True,
                        help='do not time the execution')
    parser.add_argument('--no-write', '-nw',
                        dest='output_file', action='store_false',
                        help='do not write the results')
    parser.add_argument('--no-multi', '-nm',
                        dest='multiprocessing',
                        action='store_false', default=True,
                        help='do not use multiprocessing')
    return dict(parser.parse_args(args)._get_kwargs())


@contextmanager
def timeit(message, display=True):
    """Context to time an execution."""
    start = time()
    yield
    if not display:
        return
    print("{}: {:.3f} s".format(message, time() - start))


@contextmanager
def open_output_file(output_filename):
    """None context. Used for conditional context."""
    if not output_filename:
        yield
        return
    with open(output_filename, 'w') as output_file:
        yield output_file


def check_function(func):
    """Hack for multiprocessing on CPython."""
    module = sys.modules[func.__module__]
    # Check
    if getattr(module, func.__name__, None) is func:
        return
    # Rename
    func.__name__ = "__" + func.__name__
    setattr(module, func.__name__, func)


def multiprocess_imap(func, iterator):
    """Multiprocessing version of imap."""
    pool = Pool()
    for result in pool.imap(func, iterator):
        yield result
    pool.close(), pool.join()


def parse_file(f, lines_per_case=1, header=True):
    """Generator to parse a file."""
    expression = isinstance(lines_per_case, str) and lines_per_case
    for _ in range(header):
        next(f)
    while True:
        if expression and expression.lower() == "dynamic":
            lines = ()
            lines_per_case = int(next(f).strip())
        elif expression:
            lines = (next(f),)
            variables = {
                'lines': lines,
                'line': lines[0],
                'args': lines[0].split()}
            lines_per_case = int(eval(expression, variables))
        else:
            lines = ()
        lines += tuple(next(f).strip() for _ in range(lines_per_case))
        if not lines:
            return
        yield lines


def print_result(case, result, output=None, display=True):
    """Print a result using the correct formatting."""
    line = "Case #{}: {}".format(case, result)
    if display:
        print(line)
    if output:
        output.write(line + '\n')


def solve(solver,
          input_file, output_file=True,
          lines_per_case=1, header=True, start=1,
          multiprocessing=True, timing=True, display=True):
    """Use a given solver on a given input file."""
    # Open input file
    with open(input_file) as input_f:
        # Prepare generator
        mapping = multiprocess_imap if multiprocessing else map
        parser = parse_file(input_f, lines_per_case, header)
        generator = enumerate(mapping(solver, parser), start)
        # Open output file
        if output_file is True:
            output_file = input_file.rstrip(".in") + ".out"
        with open_output_file(output_file) as output_f:
            # Time execution
            timing_message = "Execution time for {}".format(input_file)
            with timeit(timing_message, timing):
                # Loop through cases
                for case, result in generator:
                    print_result(case, result, output_f, display)


def solver(func=None, lines_per_case=1, header=True, start=1):
    """Solver decorator.

    Add two attributes `solve` and `from_cli` to the decorated function.
    Those functions provides a convenient interface to solve the problem.
    The decorated function is expected to take a list of lines corresponding
    to a single case as an argument and return the corresponding result.

    Args:
        lines_per_case (int or str): indicates how to split the cases.
            - If an integer, it is used as number of lines per cases.
            - If equals to "dynamic", it expects the first line to be the
              number of following lines. The first line is removed from the
              lines passed to the solver function.
            - If another string, it is evaluated dynamically to get the number
              of following lines. The 'line' variable is the first line of
              case. For instance, "int(line.split()[0])" is a valid value.
              It can equivalently be written as "int(args[0])".
            Defaults to 1.
        header (bool or int): number of line to ignore at the begining of
            the input file. The header is usually one line indicating the
            number of cases. Defaults to True.
        start (int): the number of the first case. Defaults to 1.
    """
    def decorator(func, solve_func=solve):
        """Solver decorator."""
        def solve(input_file, output_file=True,
                  multiprocessing=True, timing=True, display=True):
            """Solve the problem using the given input file.

            Args:
                input_file (str): name of the input file.
                output_file (str or True or None): name of the output file.
                    If True, the name of the input file is used, replacing
                    '.in' with '.out'. If None, no output file is written.
                    Defaults to True.
                multiprocessing (bool): run the cases in different processes.
                    It usually achieves a better performance.
                    Defaults to True.
                timing (bool): time the execution and print the results.
                    Defaults to True.
                display (bool): print the results to standard output.
                    Defaults to True.
            """
            return solve_func(
                func, input_file,
                output_file=output_file,
                lines_per_case=lines_per_case,
                header=header, start=start,
                multiprocessing=multiprocessing,
                timing=timing, display=display)

        def from_cli(args=None):
            """Provide a CLI interface for the solver.

            Args:
                args (list or None): list of arguments.
                    Default to 'sys.argv[1:]'.
            """
            name = func.__name__
            kwargs = get_command_line_kwargs(name, args=args)
            return func.solve(**kwargs)

        func.solve = solve
        func.from_cli = from_cli
        check_function(func)
        return func

    if func is None:
        return decorator
    return decorator(func)


# Example
if __name__ == "__main__":
    @solver
    def square(lines):
        """Return the square of the given argument."""
        return int(lines[0]) ** 2
    # Run example
    square.from_cli()
