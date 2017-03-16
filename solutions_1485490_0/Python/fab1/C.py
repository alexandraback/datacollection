#!/usr/bin/python

import sys

def parse(fname):
    r = []
    f = open(fname)
    T = f.readline()
    N = -1
    M = -1
    for line in f:
        if N == -1:
            A = -1
            B = -1
            N, M = map(int, line.split())
        elif A == -1:
            A = map(int, line.split())
        elif B == -1:
            B = map(int, line.split())
            r.append((A, B))
            N = -1
    f.close()
    return r

def s(A, B):
    if len(A) == 0 or len(B) == 0:
        return 0

    if A[1] == B[1]:
        if A[0] > B[0]:
            AA = A[:]
            AA[0] -= B[0]
            return B[0] + max( s(A[2:], B[2:]), s(AA, B[2:]) )
        elif B[0] > A[0]:
            BB = B[:]
            BB[0] -= A[0]
            return A[0] + max( s(A[2:], B[2:]), s(A[2:], BB) )
        else:
            return A[0] + s(A[2:], B[2:])

    else:
        return max( s(A, B[2:]), s(A[2:], B), s(A[2:], B[2:]) )

def solve(case):
    A,B = case
    return s(A, B)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        data = parse(sys.argv[1])
    else:
        data = parse("C-sample.in")

    i = 1
    for case in data:
        print "Case #" + str(i) + ": " + str(solve(case))
        i += 1
