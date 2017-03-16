import time
import sys

SAMPLE = """4
1? 2?
?2? ??3
? ?
?5 ?0
"""


class Problem(object):
    """
    A simple helper class for parsing Google Code Jam problem inputs and
    formatting solutions.

    (C) Vytautas Liuolia 2016
    """

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


class Solution(Problem):

    def solve_wrong(self, case):
        C, J = map(list, case)
        for pos in range(len(C)):
            c = C[pos]
            j = J[pos]
            prior = cmp(C[:pos], J[:pos])

            if c == '?' and j == '?':
                if prior > 0:
                    c = '0'
                    j = '9'
                elif prior == 0:
                    c = j = '0'
                else:
                    c = '9'
                    j = '0'

            elif c == '?':
                if prior > 0:
                    c = '0'
                elif prior == 0:
                    c = j
                else:
                    c = '9'

            elif j == '?':
                if prior > 0:
                    j = '9'
                elif prior == 0:
                    j = c
                else:
                    j = '0'

            C[pos] = c
            J[pos] = j
        return ''.join(C) + ' ' + ''.join(J)

    def solve_brute(self, C, J):
        N = len(C)
        best = (10 ** (N + 1), 0, 0)

        qC = C.count('?')
        qJ = J.count('?')

        if qC == qJ == N:
            return ('0' * N, '0' * N)

        for c_test in xrange(10 ** qC):
            for j_test in xrange(10 ** qJ):
                c = ''
                qp = 0
                for i in range(N):
                    if C[i] == '?':
                        c += str(c_test).rjust(qC, '0')[qp]
                        qp += 1
                    else:
                        c += C[i]

                j = ''
                qp = 0
                for i in range(N):
                    if J[i] == '?':
                        j += str(j_test).rjust(qJ, '0')[qp]
                        qp += 1
                    else:
                        j += J[i]

                result = (abs(int(c) - int(j)), c, j)
                if result < best:
                    best = result

        return best[1:]

    def solve(self, case):
        C, J = case
        return ' '.join(self.solve_brute(C, J))

    def parse_case(self, lines):
        return tuple(lines.next().strip().split())


if __name__ == '__main__':
    # Solution.run_sample(SAMPLE)
    Solution.run()
