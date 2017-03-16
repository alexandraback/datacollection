from copy import deepcopy
from itertools import product
for t in xrange(input()):
    print "Case #%d:"%(t+1),
    n = input()
    lst = [raw_input().split() for i in xrange(n)]
    ans = 0
    fcnt = {}; scnt = {}
    for f, s in lst:
        fcnt[f] = fcnt.get(f, 0) + 1
        scnt[s] = scnt.get(s, 0) + 1

    ans = 0
    for faker in product([0,1], repeat = n):
        fused = {}; sused = {}
        for i in xrange(n):
            if not faker[i]:
                f, s = lst[i]
                fused[f] = sused[s] = 1
        ok = 1
        for i in xrange(n):
            if faker[i]:
                f, s = lst[i]
                if f not in fused or s not in sused:
                    ok = 0
                    break
        if ok:
            ans = max(sum(faker), ans)
    print ans

