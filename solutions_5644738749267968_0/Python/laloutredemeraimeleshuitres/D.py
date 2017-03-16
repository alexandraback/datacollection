from bisect import bisect

def deceived(_n,_k):
    n = list(_n)
    k = list(_k)
    score = 0
    while n:
        if n[0] > k[0]:
            n.pop(0)
            k.pop(0)
            score += 1
        else:
            n.pop(0)
            k.pop()
    return score

def war(_n,_k):
    n = list(_n)
    k = list(_k)
    score = 0
    while n:
        ni = n.pop()
        pos = bisect(k, ni)
        if pos == len(k):
            ki = k.pop(0)
        else:
            ki = k.pop(pos)
        if ki < ni:
            score += 1
    return score

def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1),
        L = int(f.readline())
        naomi = sorted(map(float, f.readline().strip().split()))
        ken = sorted(map(float, f.readline().strip().split()))
        assert(len(naomi) == L)
        assert(len(ken) == L)
        print deceived(naomi, ken), war(naomi, ken)

import sys

parse(sys.stdin)
