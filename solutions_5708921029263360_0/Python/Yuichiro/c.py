import sys
import random
from collections import defaultdict


def solve(J, P, S, K):
    best_res = 0
    best_lst = []

    for _ in range(5000):
        jp = defaultdict(int)
        js = defaultdict(int)
        ps = defaultdict(int)
        jps = set()

        ljs = range(J)
        random.shuffle(ljs)
        lps = range(P)
        random.shuffle(lps)
        lss = range(S)
        random.shuffle(lss)

        res = 0
        lst = []

        while True:
            try:
                for j in ljs:
                    for p in lps:
                        if jp[(j, p)] < K:
                            for s in lss:
                                if js[(j, s)] < K and ps[(p, s)] < K and (j, p, s) not in jps:
                                    jp[(j, p)] += 1
                                    js[(j, s)] += 1
                                    ps[(p, s)] += 1
                                    jps.add((j, p, s))
                                    res += 1
                                    lst.append((j, p, s))
                                    raise Exception
                break
            except Exception:
                continue

        if res > best_res:
            best_res = res
            best_lst = lst
        
    print best_res
    for j, p, s in best_lst:
        print j+1, p+1, s+1


N = int(sys.stdin.readline())
for i in range(N):
    j, p, s, k = map(int, sys.stdin.readline().split())
    print "Case #{}:".format(i+1),
    solve(j, p, s, k)
