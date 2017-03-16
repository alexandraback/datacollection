#!/usr/bin/python
"Recycled Numbers"
import sys

def cycles(num):
    L = list(str(num))
    LN = len(L)
    for i in range(0, LN):
        yield int("".join(L[i:]+L[:i]))


def slow(A,B):
    pairs = []
    for n in range(A, B):
        for m in range(n+1, B+1):
            if m in list(cycles(n)):
                pairs.append((n,m))
    R = len(pairs)
    return R, pairs


def fast(A,B):
    K = B-A+1
    R = 0
    M = [False] * K
    pairs = []
    for t in range(A, B+1):
        if not M[t-A]:
            alts = sorted(set(m for m in cycles(t) if A <= m <= B))
            for a in alts:
                M[a-A] = True
            """
            for i, n in enumerate(alts[:-1]):
                for m in alts[i+1:]:
                    if m > n:
                        pairs.append((n, m))
                        R += 1
            """
            C = len(alts)
            R += (C * (C-1)) / 2
    return R, pairs


f = open(sys.argv[1])
T = int(f.readline())
for X in range(1, T+1):
    A, B = [int(x) for x in f.readline().split()]
    fR, fP = fast(A,B)
    #sR, sP = slow(A,B)
    #print sorted(fP)
    #print "fP-sP", set(fP) - set(sP)
    #print "sP-fP", set(sP) - set(fP)
    #print "Pairs", len(pairs), len(set(pairs)), sorted(pairs)
    print "Case #{}: {}".format(X, fR)
    #print "Case #{}: {} vs {}".format(X, fR, sR)
