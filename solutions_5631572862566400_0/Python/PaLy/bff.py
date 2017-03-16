from itertools import permutations
from multiprocessing.pool import Pool


def solve(args):
    n, f = args
    for i in range(n):
        f[i] -= 1
    for rr in reversed(range(2, n + 1)):
        for p in permutations(range(n), rr):
            ok = True
            for i in range(rr):
                l = p[(i + rr - 1) % rr]
                r = p[(i + 1) % rr]
                m = p[i]
                if f[m] != r and f[m] != l:
                    ok = False
                    break
            if ok:
                return rr


t = int(input())
nfs = []
for tt in range(1, t + 1):
    n = int(input())
    f = list(map(int, input().split()))
    nfs.append((n, f))

with Pool(8) as p:
    res = p.map(solve, nfs)
    for tt in range(1, t + 1):
        print("Case #" + str(tt) + ":", res[tt - 1])
