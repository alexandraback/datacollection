from math import ceil


def get_idx(k, *args):
    c = len(args)
    n = 0
    for i, x in enumerate(args):
        if x >= k:
            x = k-1
        n += x * k ** (c - i - 1)
    return n+1

t = int(input())
for ii in range(1, t+1):
    k, c, s = map(int, input().split())
    if k == s:
        print("Case #{}:".format(ii), " ".join(map(str, range(1, k+1))))
    elif s < ceil(k/(c)):
        print("Case #{}: IMPOSSIBLE".format(ii))
    else:
        ns = []
        for start in range(0, k, c):
            gets = list(range(start, start+c))
            ns.append(str(get_idx(k, *gets)))

        print("Case #{}:".format(ii), " ".join(ns))
