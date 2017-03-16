#!/usr/bin/python

from math import *

# 5
# 100 200

def gao_add(sz, cnt, i) :
    if sz > i :
        return (sz + i, cnt)
    else :
        #sz = 5
        #i = 100
        #print '%d -> %d' % (sz, i)
        ncnt = 0
        nsz = sz
        while nsz <= i :
            nsz += nsz - 1
            ncnt += 1
        #print nsz, ncnt

        #f = sz - 1
        #c = f - f * f- 2 * i + 2 * sz
        #last = (sqrt(1 - 4 * c) + 1) / 2
        #last = int(floor(last))
        #print last
        #ncnt = last - sz + 1
        #nsz = (sz + last) * ncnt / 2
        return (nsz + i, cnt + ncnt)

def rmax(r1, r2) :
    if r1[1] != r2[1] :
        if r1[1] < r2[1] :
            return r1
        else :
            return r2
    else :
        if r1[0] > r2[0] :
            return r1
        else :
            return r2

def gao(A, N, size) :
    if A == 1 :
        return len(size)
    size.sort()
    if_add = (A, 0)
    if_remove = (A, 0)
    #print A, size
    #print if_add, if_remove
    for i in size :
        r1 = gao_add(if_add[0], if_add[1], i)
        r2 = gao_add(if_remove[0], if_remove[1], i)
        r3 = rmax(if_add, if_remove)

        if_add = rmax(r1, r2)
        if_remove = (r3[0], r3[1] + 1)
        #print if_add, if_remove

    return min(if_add[1], if_remove[1])


T = int(raw_input())

for t in xrange(1, T + 1) :
    A, N = [ int(i) for i in raw_input().split() ]
    size = [ int(i) for i in raw_input().split() ]
    print 'Case #%d: %d' % (t, gao(A, N, size))
