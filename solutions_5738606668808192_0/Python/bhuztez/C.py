#!/usr/bin/env python2

from itertools import ifilter, islice

PRIMES = [2]

for i in xrange(3,101):
    if all((i%p!=0) for p in PRIMES):
        PRIMES.append(i)


def to_digits(x,n):
    return [1]+[(x>>i)&1 for i in xrange(n-1,-1,-1)]+[1]

def base_to_num(n,digits,b):
    r = 0
    for i in xrange(n):
        r = r * b + digits[i]
    return r

def first_p(n):
    for p in PRIMES:
        if n % p == 0:
            return p

def gen_numbers(N):
    for i in xrange(0,2**N):
        d = to_digits(i,N)
        p = []

        for b in xrange(2,11):
            n = base_to_num(N+2,d,b)
            x = first_p(n)
            if x is None:
                break
            p.append(x)
        else:
            yield d, p


def solve():
    N,J = map(int,raw_input().split())
    for d, p in islice(gen_numbers(N-2),J):
        print ''.join(map(str,d)), ' '.join(map(str,p))

T = int(raw_input())

for i in xrange(T):
    print 'Case #%d:' % (i+1)
    solve()
