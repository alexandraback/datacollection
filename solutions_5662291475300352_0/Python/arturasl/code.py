from fractions import Fraction as f

def dist(p1, p2):
    p1, p2 = max(p1, p2), min(p1, p2)
    return min(360 - p1 + p2, p1 - p2)

def move(h, t, norm = True):
    np = h[0] + t * h[1]
    revol = int(np / 360)
    if not norm:
        revol = 0
    return (np - 360 * revol, h[1])

def meets(h1, h2):
    assert(h1[0] <= 360 and h2[0] <= 360)
    assert(0 <= h1[0] and 0 <= h2[0])

    if h1[0] == h2[0]:
        return f(0)
    if h1[1] == h2[1]:
        return f(-1)

    # first should be faster
    if h1[1] < h2[1]:
        h1, h2 = h2, h1

    # first is behind
    if h1[0] < h2[0]:
        return f(h1[0] - h2[0], h2[1] - h1[1])

    # first is in front
    t = meets(h1, (f(360), f(0)))
    h1 = move(h1, t)
    h2 = move(h2, t)

    # first is behind
    return meets(h1, h2)

def solve():
    H = int(input())
    hikers = []
    for _ in range(H):
        p, h, s = [int(r) for r in input().split()]
        for i in range(h):
            hikers.append((f(p), f(360, s + i)))

    deer = hikers[0]
    time = 0
    for h in hikers:
        if h[0] < deer[0] or (h[0] == deer[0] and h[1] < deer[1]):
            deer = h

    t = meets(hikers[0], hikers[1])
    if t == 0:
        hikers = [move(h, f(1, 100000000000)) for h in hikers]
        deer = move(deer, f(1, 100000000000))
    t = meets(hikers[0], hikers[1])
    if t == -1 or t >= meets(deer, (f(360), f(0))):
        return 0
    return 1

    # loops = 0
    # while deer[0] < 360:
    #     if loops > 10:
    #         break
    #     print('hikers: {}'.format(hikers))
    #     print('deer before: {} (loop: {})'.format(deer, loops))
    #     meets_at_delta, meets_with = -1, deer
    #     for h in hikers:
    #         t = meets(deer, h)
    #         if deer != h and (meets_at_delta == -1 or (t != -1 and t < meets_at_delta)):
    #             meets_at_delta, meets_with = t, h
    #
    #     # no one moves faster or slower
    #     if deer == meets_with:
    #         break
    #
    #     # atleast two people are moving in the same place
    #     moved = True
    #     if meets_at_delta == 0:
    #         moved = False
    #         meets_with = deer
    #         meets_at_delta = f(1, 100000000000000)
    #
    #     deer = move(meets_with, meets_at_delta, False)
    #     hikers = [move(h, meets_at_delta) for h in hikers]
    #     loops += deer[0] < 360 and moved
    #     print('deer after: {} (loop: {}), delta: {}'.format(deer, loops, meets_at_delta))
    # return loops

T = int(input())
for t in range(1, T + 1):
    print('Case #{}: {}'.format(t, solve()))
