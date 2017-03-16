"""Provide a solver decorator for programming contests."""

# Imports
import sys
import argparse
from timeit import default_timer as time
from functools import wraps
from contextlib import contextmanager
from itertools import imap
from multiprocessing import Pool


def get_command_line_kwargs(name):
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
    return dict(parser.parse_args()._get_kwargs())


@contextmanager
def timeit(message):
    """Context to time an execution."""
    start = time()
    yield
    print "{}: {:.3f} s".format(message, time() - start)


@contextmanager
def none():
    """None context. Used for conditional context."""
    yield


def make_decorator(dec=None, cli=None):
    """Decorator to make a decorator."""
    def use_cli(dec):
        @wraps(dec)
        def set_kwargs(func=None, **default_kwargs):
            def decorator(func):
                @wraps(func)
                def wrapper(*args, **more_kwargs):
                    kwargs = default_kwargs
                    kwargs.update(more_kwargs)
                    return dec(func, *args, **kwargs)
                if cli:
                    name = func.__name__
                    wrapper.from_cli = lambda: wrapper(**cli(name))
                check_function(func)
                return wrapper
            if func:
                return decorator(func)
            return decorator
        return set_kwargs
    if dec:
        return use_cli(dec)
    return use_cli


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


def parse_file(name, lines_per_case=1, header=True):
    """Generator to parse a file."""
    dynamic = (lines_per_case == "dynamic")
    with open(name) as f:
        header and next(f)
        while True:
            if dynamic:
                lines_per_case = int(next(f))
            lines = tuple(next(f) for _ in range(lines_per_case))
            if not lines:
                return
            yield lines


def print_result(case, result, output=None, display=True):
    """Print a result using the correct formatting."""
    line = "Case #{}: {}".format(case, result)
    if display:
        print line
    if output:
        output.write(line + '\n')


@make_decorator(cli=get_command_line_kwargs)
def solver(solver,
           input_file=None, output_file=True,
           lines_per_case=1, header=True, start=1,
           multiprocessing=True, timing=True, display=True):
    """Use a given solver on a given input file."""
    # Get output file
    if output_file is True:
        output_file = input_file.rstrip(".in") + ".out"
    # Prepare solver
    imapping = multiprocess_imap if multiprocessing else imap
    parser = parse_file(input_file, lines_per_case, header)
    solver = enumerate(imapping(solver, parser), start)
    # Time the execution
    message = "Execution time for {}".format(input_file)
    with timeit(message) if timing else none():
        with open(output_file, "w") if output_file else none() as output:
            for case, line in solver:
                print_result(case, line, output, display)


# Example
if __name__ == "__main__":
    @solver
    def square(lines):
        """Return the square of the given argument."""
        return int(lines[0]) ** 2
    # Run example
    square.from_cli()
