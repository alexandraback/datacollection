# Author: Thomas P. Robitaille
# Executed using Python 3

import numpy as np


def worst_offender(combinations, K):
    best = 0
    ibest = None
    jbest = None
    kbest = None
    for i in range(J):
        for j in range(P):
            for k in range(S):
                if combinations[i, j, k] == 1:
                    vmax = max(combinations[i,j,:].sum(), combinations[:,j,k].sum(), combinations[i,:,k].sum())
                    if vmax > K:
                        if vmax > best:
                            ibest = i
                            jbest = j
                            kbest = k
                            best = vmax

    return ibest, jbest, kbest


def solve(J, P, S, K):

    combinations = np.ones((J, P, S))

    while True:

        if np.all(combinations.sum(axis=0) <= K) and np.all(combinations.sum(axis=1) <= K) and np.all(combinations.sum(axis=2) <= K):
            break

        i, j, k = worst_offender(combinations, K)

        combinations[i, j, k] = 0

    outfits = []

    for i in range(J):
        for j in range(P):
            for k in range(S):
                if combinations[i, j, k] == 1:
                    outfits.append((str(i + 1), str(j + 1), str(k + 1)))

    return outfits


with open('C-small-attempt2.in') as f:
    T = int(f.readline())
    for i in range(T):
        J, P, S, K = [int(x) for x in f.readline().split()]
        outfits = solve(J, P, S, K)
        print("Case #{0}: {1}".format(i + 1, len(outfits)))
        for outfit in outfits:
            print(" ".join(outfit))
