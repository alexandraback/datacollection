#!/usr/bin/python3

from argparse import ArgumentParser
from pprint import pprint

p = ArgumentParser()
p.add_argument('filename')
p.add_argument('-v', '--verbose', action='store_true')
p.add_argument('-n', '--limit', type=int)
opts = p.parse_args()
verbose = opts.verbose
f = open(opts.filename)

T = int(f.readline())
if opts.limit is not None and T > opts.limit:
    T = opts.limit

def debug(*args, **kwargs):
    if verbose:
        print(*args, **kwargs)
def pdebug(*args, **kwargs):
    if verbose:
        pprint(*args, **kwargs)

possible = {
        0 : [(0,0,0)],
        1 : [(1,0,0)],
        2 : [(1,1,0), (2,0,0)],
        3 : [(1,1,1), (2,1,0)],
        4 : [(2,1,1), (2,2,0)],
        5 : [(2,2,1), (3,1,1)],
        6 : [(2,2,2), (3,2,1)],
        7 : [(3,2,2), (3,3,1)],
        8 : [(3,3,2), (4,2,2)],
        9 : [(3,3,3), (4,3,2)],
        10: [(4,3,3), (4,4,2)],
        11: [(4,4,3), (5,3,3)],
        12: [(4,4,4), (5,4,3)],
        13: [(5,4,4), (5,5,3)],
        14: [(5,5,4), (6,4,4)],
        15: [(5,5,5), (6,5,4)],
        16: [(6,5,5), (6,6,4)],
        17: [(6,6,5), (7,5,5)],
        18: [(6,6,6), (7,6,5)],
        }

for casenum in range(1,T+1):
    N, S, p, *scores  = [int(x) for x in f.readline().split()]
    assert len(scores) == N

    def solve():
        always = 0
        maybe = 0
        for s in scores:
            expected_best = (s + 2) // 3
            if 2 <= s <= 28:
                surprising_best = (s + 4) // 3
            else:
                surprising_best = expected_best
            if expected_best >= p:
                always += 1
            elif surprising_best >= p:
                maybe += 1
        return always + min(S, maybe)

    output_str = solve()
    print('Case #%d:'%casenum, output_str)
