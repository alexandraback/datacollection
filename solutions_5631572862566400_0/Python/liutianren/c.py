#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

class Counter(dict):
    def __missing__(self, key):
        return 0

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        N = int(sys.stdin.readline())
        F = [int(_s)-1 for _s in sys.stdin.readline().split()]

        reps = set()
        rep = [-1 for _ in range(N)]
        looprep = [-1 for _ in range(N)]
        def findrep(i):
            if rep[i] == -2:
                rep[i] = i
                looprep[i] = i
                j = F[i]
                while j != i:
                    looprep[j] = j
                    j = F[j]
                reps.add(i)
            if rep[i] != -1:
                return rep[i], looprep[i]
            rep[i] = -2
            rep[i],lp = findrep(F[i])
            if looprep[i] < 0:
                looprep[i] = lp
            return rep[i],looprep[i]
        for i in range(N):
            findrep(i)

        res = 0
        bireps = set()
        for r in reps:
            c = 1
            i = F[r]
            while i != r:
                i = F[i]
                c += 1
            res = max(res, c)
            if c == 2:
                bireps.add(r)

        loopdis = [-1 for _ in range(N)]
        looprep_longleaf = Counter()
        def finddis(i):
            if loopdis[i] != -1:
                return loopdis[i]
            if rep[i] not in bireps:
                return
            if i in looprep:
                loopdis[i] = 0
                return 0
            loopdis[i] = finddis(F[i]) + 1
            d = max(looprep_longleaf[looprep[i]], loopdis[i])
            looprep_longleaf[looprep[i]] = d
            return loopdis[i]
        for i in range(N):
            finddis(i)

        res = max(res,sum(looprep_longleaf[r]+2+looprep_longleaf[F[r]] for r in bireps))

        print("Case #{}: {}".format(t+1, res))
