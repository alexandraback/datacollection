#!/usr/bin/env python

import sys
from math import sqrt, floor, ceil

def ispalin(x):
    return str(x) == str(x)[::-1]

def palingen(Ac, Bc):
    for ii in range(Ac, Bc+1):
        x = ii / 2 - 1
        if ii == 1:
            for jj in range(1,10):
                yield jj
        elif ii % 2 == 0:
            for jj in range(10**x, 10**(x+1)):
                yield int(str(jj) + str(jj)[::-1])
        else:
            for jj in range(10**x, 10**(x+1)):
                for kk in range(10):
                    yield int(str(jj) + str(kk) + str(jj)[::-1])

def solve(A,B):
    A_lower = int(floor(sqrt(A)))
    B_upper = int(ceil(sqrt(B)))
    count = 0
    for p in palingen(len(str(A_lower)), len(str(B_upper))):
        psq = p**2
        if psq >= A and psq <= B and ispalin(psq):
            count += 1
    return count

def main():
    assert len(sys.argv) == 2
    path = sys.argv[1]
    with open(path) as f:
        N = int(f.readline())
        for ii in range(N):
            A, B = map(int, f.readline().split(' '))
            print 'Case #{}: {}'.format(ii+1, solve(A,B))


if __name__ == '__main__':
    main()
