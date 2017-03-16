#!/usr/bin/env python
import sys
import math


input()
input()
print("Case #1:")

def can(p, h):
    for i in h:
        if p%i == 0:
            p /= i
    return (p == 1)

def makes(p, h):
    for i in p:
        if not can(i, h):
            return False
    return True

ways = []
for i in range(2, 6):
    for j in range(2, 6):
        for k in range(2, 6):
            ways.append([i, j, k])

for testcase in range(100):
    prods = [int(x) for x in input().split()]
    for way in ways:
        if makes(prods, way):
            print(''.join([str(x) for x in way]))
            break
