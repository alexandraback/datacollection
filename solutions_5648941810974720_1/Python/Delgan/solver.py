import os
import re
import sys
import math
import time
import bisect
import random
import datetime
import itertools
import functools
import collections
from contextlib import contextmanager


def debug(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


class Solver:

    def __init__(self, solve_case):
        self._solve_case = solve_case
        self._script_dir = os.path.dirname(os.path.realpath(__file__))
        self._inputs_dir = os.path.join(self._script_dir, "inputs")
        self._outputs_dir = os.path.join(self._script_dir, "outputs")
        self._solutions_dir = os.path.join(self._script_dir, "solutions")

    @contextmanager
    def _set_io(self, source):
        if not source:
            yield sys.stdin, sys.stdout
            return
        old_stdin = sys.stdin
        old_stdout = sys.stdout
        try:
            in_file = os.path.join(self._inputs_dir, "%s.in" % source)
            out_file = os.path.join(self._outputs_dir, "%s.out" % source)
            with open(in_file, "r") as inf:
                with open(out_file, "w") as ouf:
                    sys.stdin = inf
                    sys.stdout = ouf
                    yield inf, ouf
        finally:
            sys.stdin = old_stdin
            sys.stdout = old_stdout

    def _compare(self, out_file, sol_file):
        success = True
        with open(out_file, "r") as out_f:
            with open(sol_file, "r") as sol_f:
                out_lines = out_f.read().splitlines()
                sol_lines = sol_f.read().splitlines()
                for out, sol in itertools.zip_longest(out_lines, sol_lines):
                    if out != sol:
                        debug("[ERROR] %s != %s" % (out, sol))
                        success = False
        if success:
            debug("[SUCCESS] Good news: the solution seems correct!\n")
        else:
            debug("[FAILURE] The solution differs from the expected output.\n")

    def _test_solution(self, source):
        out_file = os.path.join(self._outputs_dir, "%s.out" % source)
        sol_file = os.path.join(self._solutions_dir, "%s.sol" % source)
        if os.path.isfile(sol_file):
            self._compare(out_file, sol_file)

    def solve(self, source=None):
        with self._set_io(source):
            nb = int(input())
            debug("[START] %d cases to solve:" % nb)

            total = 0
            for i in range(1, nb + 1):
                print("Case #%d:" % i, end=" ")

                start = time.process_time()
                self._solve_case()
                end = time.process_time()

                t = end - start
                total += t

                m, s = divmod(total, 60)
                debug(
                    "[%d:%02.02f] Case #%d solved in %.02f seconds" %
                    (m, s, i, t)
                )
        debug()
        self._test_solution(source)

DIGITS = (
    'ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE'
)
LETTERS = set([letter for digit in DIGITS for letter in digit])
OCCURENCES = {
    letter: sum(letter in digit for digit in DIGITS)
    for letter in LETTERS
}
ASSOC = {
    letter: tuple(digit for digit in DIGITS if letter in digit)
    for letter in LETTERS
}

def sort(string):
    string.sort(key=lambda letter: OCCURENCES[letter])

def backtrack(string, phone_number):
    if not string:
        return phone_number

    letter = string[0]

    for a in ASSOC[letter]:
        if all(x in string for x in a):
            for x in a:
                string.remove(x)
            phone_number.append(a)
            b = backtrack(string, phone_number)
            if not b:
                string.extend(a)
                sort(string)
                phone_number.pop()
            else:
                return phone_number
    return False

def solve_case():
    string = list(input())
    sort(string)
    res = backtrack(string, [])
    res.sort(key=DIGITS.index)
    phone_number = [DIGITS.index(d) for d in res]
    print(*phone_number, sep='')



Solver(solve_case).solve('large')
