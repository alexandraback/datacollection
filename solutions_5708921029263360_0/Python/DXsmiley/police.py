import copy
import collections

T = int(input())

# cache = {}

# def mask(a, b, c):
#     return 1 << (a + b * 3 + c * 9)

# def f(three, two):
#     global cache
#     if three in cache:
#         return cache[three]
#     best = 0
#     bk = three
#     for j in range(J):
#         for p in range(P):
#             for s in range(S):
#                 mx = mask(j, p, s)
#                 if mx > three:
#                     two[0, j, p] += 1
#                     two[1, s, p] += 1
#                     two[2, j, s] += 1
#                     if two[0, j, p] <= K and two[1, s, p] <= K and two[2, j, s] <= K:
#                         x, k = f(three | mx, two)
#                         x += 1
#                         if x > best:
#                             best = x
#                             bk = k | mx
#                     two[0, j, p] -= 1
#                     two[1, s, p] -= 1
#                     two[2, j, s] -= 1
#     cache[three] = (best, bk)
#     return (best, bk)

# three = set()
# two = collections.defaultdict(lambda : 0)

def twochange(j, p, s, v):
    two[0, j, p] += v
    two[1, s, p] += v
    two[2, j, s] += v

def twoscore(j, p, s):
    return two[0, j, p] + two[1, s, p] + two[2, j, s]

def twomax(j, p, s):
    return max(two[0, j, p], two[1, s, p], two[2, j, s])

def twomin(j, p, s):
    return min(two[0, j, p], two[1, s, p], two[2, j, s])

for t in range(1, T + 1):
    cache = {}
    J, P, S, K = map(int, input().split())
    # N, O = f(0, collections.defaultdict(lambda : 0))
    # print(O)
    three = set()
    two = collections.defaultdict(lambda : 0)
    for s in range(S - 1, -1, -1):
        for p in range(P - 1, -1, -1):
            for j in range(J - 1, -1, -1):
                if twomax(j, p, s) < K:
                    three.add((j, p, s))
                    twochange(j, p, s, 1)
    # while max(two.values()) > K:
    #     ms = -1
    #     x = ()
    #     for s in range(S):
    #         for p in range(P):
    #             for j in range(J):
    #                 if (j, p, s) in three:
    #                     ms = max(ms, twomax(j, p, s))
    #                     x = (j, p, s)
    #     three.remove(x)
    #     print(ms, x)
    #     twochange(*x, -1)
    print('Case #{}: {}'.format(t, len(three)))
    for a, b, c in three:
        print(a + 1, b + 1, c + 1)
