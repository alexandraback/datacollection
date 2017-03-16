#! /usr/bin/python

import sys
import itertools

t = int(input())
for nt in range(1, t + 1):
    n, j = map(int, input().split())
    ans = []

    for r in range(1, len(range(2, n - 2, 2)) + 1):
        for p in itertools.combinations(range(2, n - 2, 2), r):
            if len(ans) == j:
                break
            s = '11' + '0' * (n - 4) + '11'
            for i in p:
                s = s[:i] + '11' + s[i + 2:]
            cur = [s]
            for i in range(2, 11):
                cur.append(str(i + 1))
            ans.append(cur)

    print("CASE #%d:" % (nt))
    for jc in ans:
        print(' '.join(jc))
