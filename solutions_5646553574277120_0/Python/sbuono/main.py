#! /usr/bin/python

__author__ = 'sbuono'

import sys

def canmakeit(den, i, C, n, o):

    # print "N:", n
    if -n > len(den):
        return False
    if den[n] > i:
        return canmakeit(den, i, C, n-1, o)
    for j in range(C):
        o += den[n]
        # print "o:", o
        if o == i:
            return True
        elif o > i:
            o -= den[n]
            if canmakeit(den, i, C, n-1, o):
                return True
        else:
            if canmakeit(den, i, C, n-1, o):
                return True

    return False

with open(sys.argv[1], 'r') as f:
    nbtests = int(f.readline())
    lines = f.readlines()

for testnb, i in zip(range(1, nbtests+1), range(0, len(lines), 2)):

    C, D, V = (int(x) for x in lines[i].strip().split())
    den = [int(x) for x in lines[i + 1].strip().split()]
    den.sort()
    # print "den:", den

    res = 0
    l = [x for x in range(1, V + 1) if x not in den]
    for j in range(1, V + 1):
        # print "j:", j
        if not canmakeit(den, j, C, -1, 0):
            # print "cantmakeit"
            while l:
                t = l.pop(0)

                den.append(t)
                den.sort()
                if not canmakeit(den, j, C, -1, 0):
                    den.remove(t)
                else:
                    res += 1
                    break




    print "Case #%d: %d" % (testnb, res)