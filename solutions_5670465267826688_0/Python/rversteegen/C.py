#!/usr/bin/python

import sys
import math
import numpy as np
import time

def readline():
    return sys.stdin.readline().strip().split()

def readints():
    return [int(x) for x in readline()]


# presentat
i=2
j=3
k=4
table=[
[1,i,j,k],
[i,-1,k,-j],
[j,-k,-1,i],
[k,j,-i,-1]]

def mult(a,b):
    if a < 0:
        sign = -1
        a = -a
    else:
        sign = 1
    if b < 0:
        sign *= -1
        b = -b
    return sign * table[a-1][b-1]

def exp(a,n):
    if n == 1:
        return a
    return mult(exp(a,n/2), exp(a,n - n/2))

# p = 1
# for ii in range(-4,4+1):
#     for jj in range(-4,4+1):
#         if ii and jj:
#             assert reduce(mult, [ii, jj] * p) == exp(mult(ii, jj), p)

tstart = time.clock()

T, = readints()
for testcase in range(T):
    L,X = readints()
    line, = readline()

    if X > 12:
        X = 12 + (X % 4)

    seq = []

    for ch in line:
        seq.append(ord(ch) - ord('i') + i)

    seq = seq * X

    # seq_product = reduce(mult, seq, 1)
    # print seq_product, reduce(mult, seq)

    #print seq

    reached = [([False] * 9) for i in range(3)]
    # start with 1 for i slot
    reached[0][4+1] = True
    #print reached , "SRATR"

    ops = [-4,-3,-2,-1,1,2,3,4]

    for qu in seq:
        reached_new = [([False] * 9) for i in range(3)]
        for slot in range(3):
            for q in ops:
                if reached[slot][4+q]:
                    reached_new[slot][4+mult(q,qu)] = True
        if reached_new[0][4+i]:
            # got an i, start j slot at 1
            reached_new[1][4+1] = True
        if reached_new[1][4+j]:
            # got an j, start k slot at 1
            reached_new[2][4+1] = True
        reached = reached_new
        # print "processed", qu, "now"
        # print reached
        
    #print reached

    if reached[2][4+k]:
        print "Case #%d: YES" % ( testcase + 1)
    else:
        print "Case #%d: NO" % (testcase + 1)
    

#print "done in ",  time.clock() - tstart
