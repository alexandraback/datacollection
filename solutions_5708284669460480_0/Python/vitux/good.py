from itertools import product
import re

t = int(raw_input())
for i in xrange(t):
    k, l, s = [int(x) for x in raw_input().split()]
    keys = raw_input()
    pattern = raw_input()
    ans = 0
    mx = -1
    for curr in product(keys, repeat=s):
        sc = ''.join(curr)
        ca = 0
        for j in xrange(len(sc) - len(pattern) + 1):
            ca += sc[j: len(pattern) + j] == pattern
        mx = max(mx, ca)
        ans += ca
    ans = mx - ans * 1. / (k ** s)
    print "Case #{}: {:.9f}".format(i + 1, ans)