from collections import defaultdict
from itertools import product

t = int(input())

for case in range(1, t + 1):
    nj, np, ns, k = map(int, input().split())
    memojp = defaultdict(int)
    memojs = defaultdict(int)
    memops = defaultdict(int)

    solutions = []
    for j in range(nj):
        for p in range(np):
            if memojp[(j, p)] >= k:
                continue
            for s in range(ns):
                if memojp[(j, p)] < k and memojs[(j, s)] < k and memops[(p, s)] < k:
                    solutions.append((j, p, s))
                    memojp[(j, p)] += 1
                    memojs[(j, s)] += 1
                    memops[(p, s)] += 1
    while True:
        combs = list(set(product(range(nj), range(np), range(ns))) - set(solutions))
        improve = False
        for ii in range(len(solutions)):
            j, p, s = solutions[ii]
            memojp[(j, p)] -= 1
            memojs[(j, s)] -= 1
            memops[(p, s)] -= 1

            for i, (j1, p1, s1) in enumerate(combs):
                if memojp[(j1, p1)] >= k or memojs[(j1, s1)] >= k or memops[(p1, s1)] >= k:
                    continue
                memojp[(j1, p1)] += 1
                memojs[(j1, s1)] += 1
                memops[(p1, s1)] += 1
                for ij, (j2, p2, s2) in list(enumerate(combs))[i + 1:]:
                    if memojp[(j2, p2)] < k and memojs[(j2, s2)] < k and memops[(p2, s2)] < k:
                        memojp[(j2, p2)] += 1
                        memojs[(j2, s2)] += 1
                        memops[(p2, s2)] += 1
                        solutions = solutions[:ii] + solutions[ii+1:] + [(j1, p1, s1), (j2, p2, s2)]
                        improve = True
                        # print("Improved", j, p, s, "to", j1, p1, s1, "and", j2, p2, s2)
                        # print(memojp, k)
                        # print(memojs, k)
                        # print(memops, k)
                        break
                if improve:
                    break
                memojp[(j1, p1)] -= 1
                memojs[(j1, s1)] -= 1
                memops[(p1, s1)] -= 1
            if improve:
                break

            memojp[(j, p)] += 1
            memojs[(j, s)] += 1
            memops[(p, s)] += 1
        if not improve:
            break



    print("Case #{}: {}".format(case, len(solutions)))
    for j, p, s in solutions:
        print(j+1, p+1, s+1)
