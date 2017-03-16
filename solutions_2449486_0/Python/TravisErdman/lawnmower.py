#!/usr/bin/env python

import sys
from bitarray import bitarray

t = int(sys.stdin.readline())

def transpose(li):
    return zip(*li)

for testcase in xrange(t):
    print 'Case #' + str(testcase+1) + ': ',
    n,m = map(int,sys.stdin.readline().split())
    grass = [tuple(map(int, sys.stdin.readline().split())) for _ in xrange(n)]

    while grass:
    #find min perimeter length in [1,100]
    #remove row or column that is all that length
    #if not found, break
        l = min(ht for row in (grass[0],grass[-1],transpose(grass)[0],transpose(grass)[-1]) for ht in row)
        if not (1 <= l <= 100):
            break
        try:
            grass.remove((l,) * len(grass[0]))
        except:
            grass = transpose(grass)
            try:
                grass.remove(((l,) * len(grass[0])))
            except:
                break


    if grass:
        print 'NO'
    else:
        print 'YES'

