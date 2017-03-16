from math import sqrt; from itertools import count, islice
import re, sys

def primes(n):
    primfac = []
    d = 2
    while d*d <= n:
        while (n % d) == 0:
            primfac.append(d)  # supposing you want multiple factors repeated
            n //= d
        d += 1
    if n > 1:
       primfac.append(n)
    return primfac

def isPrime(n):

    for i in xrange(2,101):
        # print i, n , n%i
        if n%i == 0:
            return i

    return None

def solve():
    # print N,J

    sols = []
    cnt = 0
    i = -1
    while cnt<J and i<2**(N-2)-1:
        i+=1
        ns = format(i, '#0%db'%N)
        ns = '1' + ns[2:] + '1'
        # print i, cnt
        # print ns

        isP = False

        sol = []
        for base in xrange(2,11):

            num = int(ns,base)
            # print base, num
            fact = isPrime(num)
            if not fact is None:
                sol.append(fact)
            else:
                isP = True
                break
        if isP:
            continue
        sols.append((ns,sol))
        cnt+=1

    return sols

T = int(raw_input())

for i in range(T):
    N,J = map(int,raw_input().split())
    print "Case #%d:"%(i+1)
    sols = solve()
    for s, pms in sols:
        print s, ' '.join(map(str,pms))

