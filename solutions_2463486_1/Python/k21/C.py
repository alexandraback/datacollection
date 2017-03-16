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

def check(n):
    p = n*n
    if is_pal(p): return p

fair_and_square = []

def precomp():
    for i in xrange(1,10**4):
        p = gen_pal_odd(i)
        r = check(p)
        if r is not None: fair_and_square.append(r)
        p = gen_pal_even(i)
        r = check(p)
        if r is not None: fair_and_square.append(r)

def solve():
    A,B = map(int, raw_input().split())
    n = len(filter(lambda x: A <= x <= B, fair_and_square))
    return n

precomp()
T = input()
for t in xrange(T):
    print 'Case #%s: %s' % (t+1, solve())
