#!/usr/bin/env python3
# -*- coding: utf-8 -*-

tc = int(input())
for tci in range(tc):
    k, c, s = [int(token) for token in input().split(' ')]
    if s * c < k:
        print('Case #%d: IMPOSSIBLE' % (tci + 1,))
        continue

    pts = []
    for i in range((k - 1) // c + 1):
        num = 0
        for j in range(c):
            num = num * k + min(i * c + j, k - 1)
        pts.append(str(num + 1))
    print('Case #%d: %s' % (tci + 1, ' '.join(pts)))
