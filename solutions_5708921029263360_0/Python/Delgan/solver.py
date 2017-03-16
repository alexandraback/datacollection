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


def solve_case():
    j, p, s, k = map(int, input().split())
    outfits = []
    prods = list(itertools.product(range(1, s + 1), range(1, p + 1), range(1, j + 1)))
    combs_sp = {}
    combs_sj = {}
    combs_pj = {}
    for a in itertools.product(range(s + 1), range(p + 1)):
        combs_sp[a] = 0
    for b in itertools.product(range(s + 1), range(j + 1)):
        combs_sj[b] = 0
    for c in itertools.product(range(p + 1), range(j + 1)):
        combs_pj[c] = 0

    while prods:
        #S, P, J = min(prods, key=lambda x: combs_sp[(x[0], x[1])] + combs_sj[(x[0], x[2])] + combs_pj[(x[1], x[2])])
        S, P, J = min(prods, key=lambda x: (combs_sp[(x[0], x[1])] + combs_sj[(x[0], x[2])] + combs_pj[(x[1], x[2])], combs_pj[(x[1], x[2])], combs_sj[(x[0], x[2])], combs_sp[(x[0], x[1])]))
        prods.remove((S, P, J))
        if combs_sp[(S, P)] < k and combs_sj[(S, J)] < k and combs_pj[(P, J)] < k:
            combs_sp[(S, P)] += 1
            combs_sj[(S, J)] += 1
            combs_pj[(P, J)] += 1
            outfits.append((J, P, S))

    print(len(outfits))
    for out in outfits:
        print(*out)
Solver(solve_case).solve("small")
