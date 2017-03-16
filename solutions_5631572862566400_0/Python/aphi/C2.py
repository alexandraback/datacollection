from sys import stdin, stdout
import itertools
from collections import defaultdict

def maxl(ll):
    if not ll:
        return 0
    return max(len(l) for l in ll)

def solve(kidsList):

    bffs = {}
    for i, k in enumerate(kidsList):
        bffs[i+1] = k

    bffPaired = {}
    for k, bff in bffs.items():
        if k == bffs[bff]: # reciprocal
            bffPaired[k] = bff



    bffPairs = set()
    for k in bffPaired:
        bffPairs.add(tuple(sorted((k, bffPaired[k]))))

    bffPairs = list(bffPairs)


    if not bffPairs:
        best = 0
        for startK in bffs:
            seen = set()
            seen.add(startK)
            cur = startK

            while True:
                nextK = bffs[cur]
                if nextK == startK:
                    # closed cycle complete
                    best = max(best, len(seen))
                    break

                if nextK in seen:
                    # invalid cycle
                    break

                seen.add(nextK)
                cur = nextK

        return best


    best = len(bffPaired)
    frags = defaultdict(list)

    for startK in bffs:
        if startK in bffPaired:
            continue

        seen = set()
        seen.add(startK)
        cur = startK

        while True:
            nextK = bffs[cur]
            if nextK == startK:
                # closed cycle complete
                break

            if nextK in seen:
                # invalid cycle
                break

            if nextK in bffPaired:
                # ends in paired
                frags[nextK].append(seen)
                break

            seen.add(nextK)
            cur = nextK


    # consider ends in paired fragments
    for i, bffPair in enumerate(bffPairs):
        a = bffPair[0]
        b = bffPair[1]

        q = maxl(frags[a]) + maxl(frags[b]) + 2

        for j in range(len(bffPairs)):
            if i != j:
                bffPair = bffPairs[j]
                a = bffPair[0]
                b = bffPair[1]

                q += max(maxl(frags[a]), maxl(frags[b]))
                q += 2

        best = max(best, q)

    return best



T = int(stdin.readline())

for t in range(T):
    N = int(stdin.readline())
    kids = map(int, stdin.readline().strip().split())

    result = solve(kids)

    stdout.write("Case #%d: %s\n"%(t+1, result))