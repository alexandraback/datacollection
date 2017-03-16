#!/usr/bin/env python3
# -*- coding: utf-8 -*-

input()
print('Case #1:')
n, j = (int(s) for s in input().split(' '))
w = n // 2 - 2

for i in range(j):
    b = '{i:0{w}b}'.format(i=i, w=w)
    bb = '11' + ''.join(x + x for x in b) + '11'
    print(bb + ' ' + ' '.join(str(d + 1) for d in range(2, 11)))
