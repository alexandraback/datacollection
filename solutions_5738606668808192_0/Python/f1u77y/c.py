#! /usr/bin/python

import sys

def divisor(n):
    p = 3
    while p * p <= n:
        if n % p == 0:
            return str(p)
        p += 2
    return None

t = int(input())
for nt in range(1, t + 1):
    n, j = map(int, input().split())
    x = (1 << (n - 1)) + 1
    ans = []
    while len(ans) < j:
        b = bin(x)[2:]
        print(b, file=sys.stderr)
        cur = [b]
        for base in range(2, 11):
            cur.append(divisor(int(b, base)))
        if None not in cur:
            ans.append(cur)
            print("%d eta" % (j - len(ans)), file=sys.stderr)
        x += 2
    print("CASE #%d" % (nt))
    for jc in ans:
        print(' '.join(jc))
