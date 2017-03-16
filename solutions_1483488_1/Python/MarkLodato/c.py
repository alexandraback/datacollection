#!/usr/bin/python3

from argparse import ArgumentParser
from pprint import pprint

p = ArgumentParser()
p.add_argument('filename')
p.add_argument('-v', '--verbose', action='store_true')
p.add_argument('-n', '--limit', type=int)
p.add_argument('-m', '--method', choices=['brute', 'faster'], default='faster')
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

def rotations(s):
    n = len(s)
    s = s*2
    for i in range(n):
        yield s[i:i+n]

def is_recycled(a, b):
    a = str(a)
    b = str(b)
    if len(a) == len(b):
        for r in rotations(b):
            if a == r:
                return True
    return False

for casenum in range(1,T+1):
    A, B = [int(x) for x in f.readline().split()]

    def solve_brute():
        """Solve the answer using brute force."""
        count = 0
        for n in range(A, B+1):
            for m in range(n+1, B+1):
                if is_recycled(n, m):
                    count += 1
                    debug((n,m))
        return count

    def solve_faster():
        """Solve the answer using a faster method."""
        count = 0
        for n in range(A, B+1):
            seen = set()
            for s in rotations(str(n)):
                if s not in seen:
                    seen.add(s)
                    m = int(s)
                    if n < m <= B:
                        count += 1
                        debug((n,m))
        return count

    solve = {
            'brute' : solve_brute,
            'faster' : solve_faster,
            }[opts.method]

    output_str = solve()
    print('Case #%d:'%casenum, output_str)
