from sys import stdin
import itertools
import math

t = int(stdin.readline())
for i in xrange(t):
    n = int(stdin.readline())

    lst = []
    fst = {}
    scd = {}
    for j in xrange(n):        
        w1, w2 = stdin.readline()[:-1].split(' ')
        lst.append((w1, w2))
        if w1 not in fst:
            fst[w1] = 1
        else:
            fst[w1] += 1
        if w2 not in scd:
            scd[w2] = 1
        else:
            scd[w2] += 1

    cd = []
    fst_non_cd = set()
    scd_non_cd = set()
    for w1, w2 in lst:
        if fst[w1] > 1 and scd[w2] > 1:
            cd.append((w1, w2))
        else:
            fst_non_cd.add(w1)
            scd_non_cd.add(w2)

    sol = 0
    for w1, w2 in cd:
        if w1 in fst_non_cd and w2 in scd_non_cd:
            sol += 1
    sol = sol + int(math.sqrt(len(cd) - sol))
    print 'Case #%d: %d' % ((i+1), sol)
