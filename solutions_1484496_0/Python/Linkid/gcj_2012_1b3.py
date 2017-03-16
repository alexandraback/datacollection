#!/usr/bin/python
# -*- coding: utf-8 -*-
## Problem C. Equal Sums (GCJ Round 1B 2012)


import itertools


def eqsum(N, S):
    ok = 1
    i = 2
    notfind = 1

    while (ok and i < N):
        combi = list(itertools.combinations(S, i))
        combi2 = map(sum, combi)
        for j, k in enumerate(combi2):
            combi_out = combi2[:j] + combi2[j+1:]
            if (k in S):
                print k
                notfind = 0
            elif (k in combi_out):
                combi_k = combi[j]
                combi_kk = combi[1+combi_out.index(k)]
                if combi_k != combi_kk:
                    print " ".join(str(x) for x in combi_kk)
                    notfind = 0

            if not notfind:
                print " ".join(str(x) for x in combi[j])
                ok = 0
                break
        i += 1

    return notfind

if __name__ == "__main__":
    T = int(raw_input()) ## nb of test cases

    for x in xrange(T):
        tab = map(int, raw_input().split())
        N, S = tab[0], tab[1:]

        print "Case #%d:" %(x+1)
        checkbn = eqsum(N, S)
        if checkbn:
            print "Impossible"
