from __future__ import division

T = int(raw_input())

for t in xrange(1, T+1):
    D = raw_input()
    arr = map(int, raw_input().split())
    highest = max(arr)

    res = highest

    for max_stack in xrange(1, highest):
        splits = 0
        for i in arr:
            while i > max_stack:
                i -= max_stack
                splits += 1
        res = min(res, splits + max_stack)

    print("Case #{}: {}".format(t, res))
