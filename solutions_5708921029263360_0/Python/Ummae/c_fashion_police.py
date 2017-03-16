import sys
sys.setrecursionlimit(65535000)
rl = lambda: sys.stdin.readline().strip()
from itertools import combinations



T = int(rl())
for tcase in range(1, T + 1):
    J, P, S, K = map(int, rl().split())

    cnts = 0
    single_cnts = {}
    pair_cnts = {}
    rets = []
    while True:
        incs = False
        for j in range(1, J + 1):
            for p in range(1, P + 1):
                for s in range(1, S + 1):
                    item = (j, p, s)
                    if single_cnts.get((j, p, s), 0) >= 1:
                        continue
                    pair1 = (j, p, 0)
                    if pair_cnts.get(pair1, 0) >= K:
                        continue
                    pair2 = (j, 0, s)
                    if pair_cnts.get(pair2, 0) >= K:
                        continue
                    pair3 = (0, p, s)
                    if pair_cnts.get(pair3, 0) >= K:
                        continue
                    cnts += 1
                    single_cnts[(j, p, s)] = 1
                    pair_cnts[pair1] = pair_cnts.get(pair1, 0) + 1
                    pair_cnts[pair2] = pair_cnts.get(pair2, 0) + 1
                    pair_cnts[pair3] = pair_cnts.get(pair3, 0) + 1
                    incs = True
                    rets.append((j, p, s))
                    # print (j, p, s)
        if not incs:
            break
    print 'Case #%d: %d' % (tcase, cnts)
    for j, p, s in rets:
        print j, p, s
