#!/usr/bin/evn python3

import os
import re


# noinspection PyPep8Naming
class CodeJamBase:
    def __init__(self):
        print(type(self).__name__)
        self.input_file_name, self.output_file_name = self.find_input_and_output_files()
        self.input = None
        self.output = None
        print('Reading from {0}, outputting to {1}'.format(self.input_file_name, self.output_file_name))

    @staticmethod
    def find_input_and_output_files():
        files = sorted(list(filter(os.path.isfile, os.listdir('.'))), reverse=True)
        patterns = ['^[A-Z]-large(-(attempt\d?|practice(-\d)?))?\.in$',
                    '^[A-Z]-small(-(attempt\d?|practice(-\d)?))?\.in$',
                    '^sample\.in$']
        for pattern in patterns:
            prog = re.compile(pattern)
            for file in files:
                if prog.match(file):
                    return file, re.sub('\.in$', '', file) + '.out'
        return 'input.in', 'output.out'

    def __enter__(self):
        self.input = open(self.input_file_name, 'r')
        try:
            self.output = open(self.output_file_name, 'w')
        except:
            self.input.close()
            raise
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        try:
            self.input.close()
        finally:
            self.output.close()
        return False

    def solve_problem(self):
        if self.input is None or self.output is None:
            raise AssertionError('Input/output file not opened.')
        n_test_cases = int(self.input.readline().rstrip('\n'))
        for i in range(1, n_test_cases + 1):
            input_vars = self.read_input(i)
            result = self.solve_case(*input_vars)
            self.write_output_for_case(i, result)
        print('Solved!')

    def solve_case(self, *args):
        raise NotImplementedError('solve_case not implemented')

    def read_input(self, i):
        raise NotImplementedError('read_input not implemented')

    def write_output_for_case(self, i, result):
        to_output = "Case #{0}: {1}".format(i, result)
        print(to_output)
        self.output.write(to_output + "\n")

    def _read_n_and_x_lines(self, x=None, split_lines=False, map_func=None):
        n = self._read_line(map_func=int)
        if x is None:
            x = n
        return n, self._read_x_lines(x, split_lines, map_func)

    def _read_n_and_first_line(self, split_lines=False, map_func=None):
        n, x = self._read_n_and_x_lines(x=1, split_lines=split_lines, map_func=map_func)
        return n, x[0]

    def _read_x_lines(self, x=1, split_lines=False, map_func=None):
        lines = []
        if split_lines:
            split_lines = ' '
        for j in range(x):
            line = self.input.readline().rstrip('\n')
            if split_lines:
                line = line.split(split_lines)
                if map_func is not None:
                    line = list(map(map_func, line))
            elif map_func is not None:
                line = map_func(line)
            lines.append(line)
        return lines

    def _read_line(self, split_lines=False, map_func=None):
        return self._read_x_lines(1, split_lines, map_func)[0]

    def _multiple_n_and_repeat_x_lines(self, x=None, split_lines=False, map_func=None):
        all_n = self._read_line(split_lines=True, map_func=int)
        all_lines = []
        for n in all_n:
            current_x = n if x is None else x
            all_lines.append(self._read_x_lines(current_x, split_lines, map_func))
        return all_n, all_lines

    def _repeat_n_and_x_lines(self, x=None, split_lines=False, map_func=None, repeat=2):
        all_N = []
        all_lines = []
        for i in range(repeat):
            N, lines = self._read_n_and_x_lines(x, split_lines, map_func)
            all_N.append(N)
            all_lines.append(lines)
        return all_N, all_lines

    @staticmethod
    def _impossible():
        return 'IMPOSSIBLE'


class CodeJam(CodeJamBase):
    def read_input(self, i):
        return self._read_line(True, int)

    @staticmethod
    def _impossible():
        return 'INSOMNIA'

    def solve_case(self, n):
        if n == 0:
            return self._impossible()
        seen = []
        for i in range(1, 1000000000):
            p = i * n
            for x in str(p):
                if x not in seen:
                    seen.append(x)
                    if len(seen) == 10:
                        return p
        raise Exception('Did not find for n={0}'.format(n))


def main():
    # cj = CodeJam()
    # for i in range(1, 1000001):
    #    print(i, cj.solve_case(i))

    with CodeJam() as problem:
        problem.solve_problem()


if __name__ == "__main__":
    main()
