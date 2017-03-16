from __future__ import division
from sys import argv
from itertools import izip

def ken_play(n, ken):
    for k in ken:
        if k > n:
            return k
    return ken[0]

def war(naomi, ken):
    score = 0
    for n in naomi:
        k = ken_play(n,ken)
        if n > k:
            score += 1
        ken.remove(k)
    return score

def dwar(naomi, ken):
    score = 0
    for n in naomi:
        if n < ken[0] and len(ken)>1:
            t = ken[-2]
        else:
            t = ken[-1]
        k = ken_play(t, ken)
        if n > k:
            score += 1
        ken.remove(k)
    return score

f = open(argv[1], 'r')

T = int(f.readline()[:-1])
for case in xrange(1,T+1):
    N = int(f.readline()[:-1])
    nmi = map(float, f.readline()[:-1].split(' '))
    ken = map(float, f.readline()[:-1].split(' '))
    nmi = sorted(nmi)
    ken = sorted(ken)
    print "Case #%d:" % case, dwar(nmi, list(ken)), war(nmi, list(ken))
