#!/usr/bin/env python

def calc(x, a, b):
    res = 0
    for y in x:
        if y > b:
            break
        if y >= a:
            res += 1
    return res

def palindrome(k):
    s = str(k)
    return s == s[::-1]

x = []
i = 1
while i * i <= 1e14:
    if palindrome(i) and palindrome(i * i):
        x.append(i * i)
    i += 1

T = input()
for t in xrange(T):
    a, b = (int(s) for s in raw_input().split())
    print 'Case #%d: %d' % (t + 1, calc(x, a, b))
