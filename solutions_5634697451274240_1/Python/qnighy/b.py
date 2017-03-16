#!/usr/bin/env python3
# -*- coding: utf-8 -*-

tc = int(input())

for tci in range(tc):
    s = input() + '+'
    print('Case #%d: %d' % (tci + 1, s.count('+-') + s.count('-+')))
