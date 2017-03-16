#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import itertools

tc = int(input())

for tci in range(tc):
    n = int(input())

    if n == 0:
        print('Case #%d: INSOMNIA' % (tci + 1,))
        continue

    s = set()
    for i in itertools.count(1):
        s |= set(str(i * n))
        if len(s) == 10:
            print('Case #%d: %d' % (tci + 1, i * n))
            break
