import argparse
import itertools
import multiprocessing
import sys
import time


def global_solve(index):
    """A dirty way to get around pickling limitations when multiprocessing."""
    return global_solve.instance.solve_single(index)


class Problem(object):
    """
    A simple helper class for parsing Google Code Jam problem inputs and
    formatting solutions.

    It also allows paralellizing tasks by multiprocessing in order to work
    around Python's limited (due to GIL) threading.

    (C) Vytautas Liuolia 2016
    """

    SAMPLE = None

    def __init__(self):
        self.cases = []

    def parse_case(self, lines):
        raise NotImplementedError

    def solve(self, case):
        raise NotImplementedError

    def solve_single(self, index):
        start = time.time()
        result = str(self.solve(self.cases[index]))
        elapsed = time.time() - start
        return result, elapsed

    def read_cases(self, lines=None):
        if lines is None:
            lines = (line.strip() for line in sys.stdin)
        amount = int(lines.next())
        for index in xrange(amount):
            self.cases.append(self.parse_case(lines))

    def solve_all(self, processes=None, verbose=False):

        indices = xrange(len(self.cases))
        processes = processes or multiprocessing.cpu_count()

        if processes > 1:
            global_solve.instance = self
            pool = multiprocessing.Pool(processes=processes)
            results = pool.imap(global_solve, indices)
        else:
            results = itertools.imap(self.solve_single, indices)

        for index, (result, elapsed) in enumerate(results):
            if verbose:
                message = "Solved case #{0} in {1} s\n".format(
                    index + 1, round(elapsed, 6))
                sys.stderr.write(message)
                sys.stderr.flush()
            print "Case #{0}: {1}".format(index + 1, result)
            sys.stdout.flush()

    @classmethod
    def main(cls):
        parser = argparse.ArgumentParser(
            description='Reads Code Jam problem input and outputs solutions.')
        parser.add_argument(
            '-s', '--sample', action='store_true',
            help='run the predefined sample instead of input')
        parser.add_argument(
            '-v', '--verbose', action='store_true',
            help='print progress information in stderr')
        parser.add_argument(
            '-p', '--processes', type=int, default=0,
            help='amount of processes to use (default: CPU count)')
        args = parser.parse_args()

        lines = None
        if args.sample:
            if cls.SAMPLE is None:
                raise NotImplementedError
            lines = iter(cls.SAMPLE.splitlines())

        problem = cls()
        problem.read_cases(lines)
        problem.solve_all(processes=args.processes, verbose=args.verbose)


class Solution(Problem):

    SAMPLE = """4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
"""

    def solve_sort(self, J, P, S, K):
        possible = set()
        JP = {}
        JS = {}
        PS = {}

        for j in range(J):
            for p in range(P):
                for s in range(S):
                    possible.add((j, p, s))
                    JP[(j, p)] = 0
                    JS[(j, s)] = 0
                    PS[(p, s)] = 0

        Jvals = {j: 0 for j in range(J)}
        Pvals = {p: 0 for p in range(P)}
        Svals = {s: 0 for s in range(S)}

        result = set()

        while True:
            best = None
            best_score = None

            for j, p, s in possible:
                score = sorted([JP[j, p], JS[j, s], PS[p, s]], reverse=True)
                if score[0] >= K:
                    continue

                score += sorted([Jvals[j], Pvals[p], Svals[s]], reverse=True)
                if best is None or score < best_score:
                    best = (j, p, s)
                    best_score = score

            if best is None:
                break

            result.add(best)
            possible.remove(best)

            jb, pb, sb = best

            Jvals[jb] += 1
            Pvals[pb] += 1
            Svals[sb] += 1

            JP[(jb, pb)] += 1
            JS[(jb, sb)] += 1
            PS[(pb, sb)] += 1

        return sorted(result)

    def solve(self, case):
        combinations = self.solve_sort(*case)
        result = str(len(combinations)) + '\n'
        for combination in combinations:
            result += ' '.join(str(i+1) for i in combination) + '\n'
        return result.rstrip()

    def parse_case(self, lines):
        return tuple(map(int, lines.next().split()))


if __name__ == '__main__':
    Solution.main()
