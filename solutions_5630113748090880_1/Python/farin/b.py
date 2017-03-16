#!/usr/bin/env python3
from collections import Counter

def solve(n):
    c = Counter()
    for i in range(2*n-1):
        for i in map(int, input().split()):
            c[i] += 1
    missing = []
    for i, cnt in c.items():
        if cnt % 2:
            missing.append(i)
    missing.sort()
    return ' '.join(map(str, missing))


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
