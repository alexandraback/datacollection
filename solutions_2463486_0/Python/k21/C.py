#!/usr/bin/python

def is_pal(n):
    s = str(n)
    return s == s[::-1]

def gen_pal_even(n):
    s = str(n)
    return int(s + s[::-1])

def gen_pal_odd(n):
    s = str(n)
    return int(s + s[-2::-1])

def check(n, A, B):
    p = n*n
    if A <= p <= B and is_pal(p): return p

def solve():
    A,B = map(int, raw_input().split())
    n = 0
    for i in xrange(1,1000):
        p = gen_pal_odd(i)
        r = check(p, A, B)
        if r is not None: n += 1
        p = gen_pal_even(i)
        r = check(p, A, B)
        if r is not None: n += 1
    return n

T = input()
for t in xrange(T):
    print 'Case #%s: %s' % (t+1, solve())
