#!/usr/bin/python

import sys

def add(A, N, motes, W, MAX):
    for i in range(0,N):
        mote = motes[i]
        if mote < A:
            A += mote
        else:
            MIN = W + N - i
            if W + 1 > MAX:
                return W + N + 1
            A2 = A*2 -1
            W += 1
            start = i
            if A2 > mote:
                start = i + 1
                A2 += mote
            if A2 != A:
                W2 = W
                W = add(A2, N-start, motes[start:], W2, MIN)
                if W > MIN:
                    return MIN
                else:
                    return W
            else:
                return MIN
    return W

cases = int(sys.stdin.readline())
for case in range(1,cases+1):
    A,N = map(int,sys.stdin.readline().rstrip().split(' '))
    motes = sorted(map(int,sys.stdin.readline().rstrip().split(' ')))
    W = add (A,N,motes, 0, N+1)
    print "Case #"+str(case)+": "+str(W)
