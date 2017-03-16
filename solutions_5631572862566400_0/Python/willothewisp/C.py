from collections import Counter, deque
from itertools import combinations

# O(N^2), can also be done in O(N) if more careful
def go(N, F):
    loop = 0
    for start in range(N):
        mark = {}
        i = start
        k = 0
        while i not in mark:
            mark[i] = k
            i = F[i]
            k += 1
        loop = max(loop, k - mark[i])

    quiver = [[] for _ in range(N)]
    for i in range(N):
        quiver[F[i]].append(i)
    vis = set()
    horns = 0
    for i in range(N):
        if F[F[i]] == i and i not in vis and F[i] not in vis:
            vis.add(i)
            vis.add(F[i])
            sofar = [0, 0]
            for side, start in enumerate([i, F[i]]):
                frontier = deque([(start, 0)])
                while frontier:
                    u, k = frontier.popleft()
                    for v in quiver[u]:
                        if v != i and v != F[i]:
                            frontier.appendleft((v, k+1))
                    sofar[side] = max(sofar[side], k)
            horns += sofar[0] + sofar[1] + 2

    return max(loop, horns)


T = int(input())
for tc in range(T):
    N = int(input())
    F = [int(s)-1 for s in input().split()]
    print("Case #{}: {}".format(tc+1, go(N, F)))