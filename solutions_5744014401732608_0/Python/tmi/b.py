""" LIMITS:
    for i in xrange(100):
        for j in xrange(100):
            do_something(i, j)
    Binary search
"""

import unittest
from collections import defaultdict

problem_name = 'B'
attempt = None
attempt = '0'
# attempt = 'L'
# attempt = 'p'
# attempt = 'P'


class TestSolveIt(unittest.TestCase):

    def test(self):
        print solve_it("2 1")
        print solve_it("5 4")
        # import ipdb; ipdb.set_trace()
        print solve_it("4 20")
        # self.assertEqual("19 20", solve_it("4 4"))


def walk(B, M):
    remaining = M
    matrix = [[0 for _ in xrange(B)] for __ in xrange(B)]
    hole = B - 1
    if remaining == 0:
        return matrix

    # len = 1
    matrix[0][hole] = 1
    remaining -= 1
    if remaining == 0:
        return matrix

    # # len = 2
    # for i in xrange(1, hole):
    #     matrix[0][i] = 1
    #     matrix[i][hole] = 1
    #     remaining -= 1
    #     if remaining == 0:
    #         return matrix

    for i in xrange(0, hole):
        for j in xrange(i + 1, hole):
            matrix[i][j] = 1
            matrix[j][hole] = 1
            remaining -= 1
            if remaining == 0:
                return matrix
    return None


def solve_it(_in):
    print _in
    b, m = _in.split(" ")
    B = int(b)
    M = int(m)

    # if B == 2:
    #     if M == 1:
    #         out = "%s\n" % possible
    #         out += "01\n"
    #         out += "00"
    #     else:
    #         out = impossible
    #     return out

    matrix = walk(B, M)
    return matrix


# MAIN


if __name__ == '__main__':
    if attempt is None:
        unittest.main()
    else:
        if attempt == 'L':
            file_name = '%s-large' % problem_name
        elif attempt == 'p':
            file_name = '%s-small-practice' % problem_name
        elif attempt == 'P':
            file_name = '%s-large-practice' % problem_name
        else:
            file_name = '%s-small-attempt%s' % (problem_name, attempt)
        dir_path = __file__.rsplit('/', 1)[0]

        with open('%s/%s.in' % (dir_path, file_name), 'r') as cases_in:
            with open('%s/%s.out' % (dir_path, file_name), 'w') as cases_out:
                total_cases = int(cases_in.next()[:-1])

                # NEXT LINES ARE SPECIFIC
                impossible = 'IMPOSSIBLE\n'
                possible = 'POSSIBLE'
                _out = ""

                for case_number in xrange(total_cases):
                    _in = cases_in.next()[:-1]
                    out = solve_it(_in)
                    if out is None:
                        _out = impossible
                    else:
                        _out = "%s\n" % possible
                        for i in out:
                            _out += "%s\n" % ("".join([str(s) for s in i]))
                    case_output = 'Case #%s: %s' % (case_number + 1, _out[:-1])
                    print case_output
                    cases_out.write('%s\n' % case_output)
