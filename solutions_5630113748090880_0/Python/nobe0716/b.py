__author__ = 'sunghyo.jung'

from collections import Counter

for t in range(1, int(input().strip()) + 1):
    n = int(input().strip())
    c = Counter()
    for i in range(2 * n - 1):
        soldiers = list(map(int, input().strip().split()))
        c += Counter(soldiers)
    r = []
    for k in sorted(c.keys()):
        if c[k] % 2 == 1:
            r.append(k)
    ans = " ".join(map(str, r))
    print("Case #%d: %s" % (t, ans))

