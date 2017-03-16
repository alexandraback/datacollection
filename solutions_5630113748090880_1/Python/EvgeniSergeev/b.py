#from math import *
#from collections import Counter
def rl(s): return xrange(len(s))

INF = 2147483647


import sys
stdin = sys.stdin

T =        int( stdin.readline().strip() )
for icase in range(1, T+1):
    N =        int( stdin.readline().strip() )
    have = []
    for i in range(2*N-1):
        rowcol = map(int, stdin.readline().strip().split())
        have.append(rowcol)

    smallfill = []
    largefill = []
    taken = [False] * len(have)
    for i in range(N):
        smallest = INF
        for k, r in enumerate(have):
            if taken[k]: continue
            smallest = min(smallest, r[i])
        pair = []
        for k, r in enumerate(have):
            if taken[k]: continue
            if r[i] == smallest:
                pair.append(k)
        assert len(pair) <= 2
        if len(pair) < 2:
            break
        smallfill.append(pair)
        taken[pair[0]] = True
        taken[pair[1]] = True

    for i in reversed(range(N)):
        largest = -1
        for k, r in enumerate(have):
            if taken[k]: continue
            largest = max(largest, r[i])
        pair = []
        for k, r in enumerate(have):
            if taken[k]: continue
            if r[i] == largest:
                pair.append(k)
        assert len(pair) <= 2
        if len(pair) < 2:
            break
        largefill.append(pair)
        taken[pair[0]] = True
        taken[pair[1]] = True

    the_non_taken = None
    for i in range(len(taken)):
        if not taken[i]:
            the_non_taken = have[i]

    rr = [None] * N
    rcindex = len(smallfill)
    rr[rcindex] = the_non_taken[rcindex]
    for i in range(len(smallfill)):
        a, b = smallfill[i]
        p, q = have[a][rcindex], have[b][rcindex]
        if the_non_taken[i] == p:
            rr[i] = q
        else:
            rr[i] = p

    for i in range(len(largefill)):
        a, b = largefill[i]
        p, q = have[a][rcindex], have[b][rcindex]
        if the_non_taken[N-1-i] == p:
            rr[N-1-i] = q
        else:
            rr[N-1-i] = p

    print "Case #%d:" % icase, ' '.join(map(str, rr))
            




