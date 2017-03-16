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


def is_possible(p, q, gen=40):
    return (p*pow(2, 40, q)) % q == 0


def solve(p, q, maxg=40):
    if not is_possible(p, q, maxg):
        return 'impossible'

    if p == 1 and q == 1:
        return 0

    g = 0

    while p * (2**g) < q:
        g += 1

    pan, qan = p*2**g - q, q*2**g

    while not is_possible(pan, qan, maxg - g):
        g += 1
        pan, qan = p*2**g - q, q*2**g

    return g


def read_case(fp):
    p, q = map(int, fp.readline().strip().split('/'))
    return p, q


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
