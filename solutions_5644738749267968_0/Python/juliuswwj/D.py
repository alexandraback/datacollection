#!/usr/bin/python


import sys, io

def getwar(a, b, N):
    i = 0
    j = 0
    while i<N:
        while j<N and b[j] < a[i]:
            j += 1
        if j>=N: break
        i += 1
        j += 1
    return N - i

def getdwar(a, b, N):
    i = 0
    j = 0
    mj = N
    c = 0
    while j<mj:
        while i<N and j<mj and a[i] < b[j]:
            i += 1
            mj -= 1
        while i<N and a[i] > b[j]:
            i += 1
            j += 1
            c += 1
    return c

T = int(sys.stdin.readline())
for t in range(T):
    N = int(sys.stdin.readline())
    a = map(float, sys.stdin.readline().split())
    b = map(float, sys.stdin.readline().split())
    a.sort()
    b.sort()

    #print a
    #print b
    
    print 'Case #%d: %d %d' % (t+1, getdwar(a, b, N), getwar(a, b, N))
    