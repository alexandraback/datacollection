from __future__ import print_function
from __future__ import division
import sys
#from itertools import izip, ifilter, imap
#from collections import defaultdict

import gcj_util
from gcj_util import (
    dprint,
    read_ints,
    read_floats,
    read_int,
)


def solve_large(A, B, K):
    pass


def solve_gen(A, B, K):
    for a in range(0, A):
        for b in range(0, B):
            if a & b < K:
                yield a, b


def solve_naive(A, B, K):
    count = 0
    for x in solve_gen(A, B, K):
        count += 1
    return count


solve = solve_naive

def read_case(fp):
    A, B, K = read_ints(fp)
    return A, B, K


def write_result(fp, casenum, result):
    fp.write('Case #%d: %s\n' % (casenum, result))
    fp.flush()


def read_cases(fp):
    T = read_int(fp)
    for i in range(T):
        yield read_case(fp)


if __name__ == '__main__':
    if len(sys.argv) > 1:
        gcj_util.DEBUG = True

    in_fp = sys.stdin
    out_fp = sys.stdout
    for casenum, case in enumerate(read_cases(in_fp)):
        result = solve(*case)
        write_result(out_fp, casenum + 1, result)
