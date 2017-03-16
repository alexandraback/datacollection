"""
A tiny Python library for parsing Google Code Jam problem inputs and formatting
solutions.

(C) Vytautas Liuolia 2016
"""
import time
import sys


class Problem(object):
    """Encapsulates a single GCJ problem."""

    def __init__(self):
        self.cases = []

    def parse_case(self, lines):
        raise NotImplementedError

    def solve(self, case):
        raise NotImplementedError

    def read_cases(self, lines=None):
        if lines is None:
            lines = (line.strip() for line in sys.stdin)
        amount = int(lines.next())
        for index in xrange(amount):
            self.cases.append(self.parse_case(lines))

    def print_report(self, verbose=False):
        for index, case in enumerate(self.cases):
            start = time.time()
            result = self.solve(case)
            elapsed = time.time() - start
            if verbose:
                print "Solved case {0} in  {1} s".format(case, elapsed)
            print "Case #{0}: {1}".format(index + 1, result)
            if verbose:
                print ''

    @classmethod
    def run(cls):
        task = cls()
        task.read_cases()
        task.print_report()

    @classmethod
    def run_sample(cls, data):
        if isinstance(data, basestring):
            data = data.splitlines()
        task = cls()
        task.read_cases(iter(data))
        task.print_report(verbose=True)
