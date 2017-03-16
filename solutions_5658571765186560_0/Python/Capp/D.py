#!/usr/bin/env python

from sys import stdin, stderr

## return True: RICHARD, can't cover all area
def check(X, R, C):
    if (R * C) % X != 0: return True
    N = min(R, C)
    M = max(R, C)
    if X <= 2*N-2: return False
    if X >= 2*N+1: return True
    if N == 1: return False
    if N == 2:
        if X == 3: return False
        if X == 4: return True
    if X == 2*N-1:
        for m in range(1, N/2+1):
            isbreak = False
            for i in range(m+1, M-N+m):
                if (i * N - m) % X == 0:
                    isbreak = True
                    break
                pass
            if not isbreak: return True
            pass
        return False
    if X == 2*N:
        for m in range(1, N/2+1):
            isbreak = False
            for i in range(m+1, M-N+m-1):
                if (i * N - m) % X == 0:
                    isbreak = True
                    break
                pass
            if not isbreak: return True
            pass
        return False
    return False

T = int(stdin.readline())
for t in range(T):
    X, R, C = [int(c) for c in stdin.readline().split()]


    ret = check(X, R, C)

    print >>stderr, "Debug:", t, X, R, C, ret

    print "Case #%d:" % (t+1),
    if ret: print "RICHARD"
    else:   print "GABRIEL"
