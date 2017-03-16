#!/usr/bin/env python
# Wentao Han (wentao.han@gmail.com)

import sys

T = int(sys.stdin.readline().strip())
for x in range(1, T + 1):
    a = [int(e) for e in sys.stdin.readline().split()]
    N = a[0]
    S = a[1]
    p = a[2]
    t = a[3:]
    y = 0
    for s in t:
        q, r = divmod(s, 3)
        if (q >= p) or (r > 0 and q + 1 >= p):
            y += 1
        elif (S > 0) and ((r == 0 and q > 0 and q + 1 >= p) or (r == 2 and q + 2 >= p)):
            S -= 1
            y += 1
    sys.stdout.write('Case #%d: %d\n' % (x, y))
