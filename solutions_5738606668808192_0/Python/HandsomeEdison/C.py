#!/usr/bin/env python

import gmpy2
import math

def solve(n, j):
    limit = 2 ** (n - 2)
    cnt = 0
    for i in xrange(0, limit):
        s = '1' + "{0:b}".format(i).zfill(n - 2) + '1'
        
        prime = False
        for base in xrange(2, 11):
            number = int(s, base)
            if gmpy2.is_prime(number):
                prime = True
                break
        if prime:
            continue
        
        divisors = []
        for base in xrange(2, 11):
            number = int(s, base)
            for k in xrange(2, 1000):
                if number % k == 0:
                    divisors.append(k)
                    break
        if len(divisors) < 9:
            continue

        print s, ' '.join(str(x) for x in divisors)

        cnt += 1
        if cnt == j:
            break

if __name__ == "__main__":
    T = input()
    for i in xrange(T):
        N, J = map(int, raw_input().split())
        print 'Case #{}:'.format(i + 1)
        solve(N, J)
