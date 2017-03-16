#!/usr/bin/python
import sys
import operator

def product(xs):
    return reduce(operator.mul, xs, 1)

def solve(A, B, p):
    # consider the option of hitting enter now
    best = B + 2
    for n in xrange(A+1):
        # Calculate expected keystrokes for n backspaces
        e = 2*B - A + 2 + 2*n - product(p[:A-n]) * (B+1)
        best = min(best, e)
    return best

if __name__ == '__main__':
    with open(sys.argv[1], 'rU') as fin, open(sys.argv[2], 'w') as fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            A, B = map(int, fin.readline().split())
            p = map(float, fin.readline().split())
            soln = solve(A, B, p)
            print >> fout, "Case #{0}: {1:.6f}".format(case, soln)
