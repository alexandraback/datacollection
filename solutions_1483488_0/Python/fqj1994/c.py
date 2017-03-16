#!/usr/bin/env python

def distinguish(seq):
    return {}.fromkeys(seq).keys()
def find_recycled(n):
    N = str(n)
    L = []
    for i in range(len(N) - 1):
        S = N[i+1:] + N[0:i+1]
        if S[0] != '0' and int(S) > n:
            L.append(int(S))
    return L
T = input()
for I in range(T):
    A, B = map(int, raw_input().split(' '))
    s = 0
    for i in range(A, B + 1):
        XX = distinguish(filter(lambda x: A <= x <= B, find_recycled(i)))
        s += len(XX)
    print "Case #%d: %d" % (I + 1, s)
