#!/usr/bin/python
import sys, collections, copy

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def calc_cheat(naomi, ken, N):
    w = 0
    while len(naomi):
        if naomi[0] < ken[0]:
            ken.pop(-1)
            naomi.pop(0)
        else:
            naomi.pop(0)
            ken.pop(0)
            w = w + 1

    return w
            
def calc_optimal(naomi, ken, N):
    j = 0
    garbage = 0
    for i in xrange(0,N):
        while j < N and naomi[i] > ken[j]:
            garbage = garbage + 1
            j = j + 1
        if j == N:
            return garbage
        j = j + 1
    return garbage
            
for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    N = int(data.pop(0))
    naomi = sorted([ float(x) for x in data.pop(0).split() ])
    ken = sorted([ float(x) for x in data.pop(0).split() ])

    cheat = calc_cheat(copy.copy(naomi), copy.copy(ken), N)
    optimal = calc_optimal(copy.copy(naomi), copy.copy(ken), N)

    print cheat, optimal




