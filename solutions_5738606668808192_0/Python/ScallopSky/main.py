#! /usr/bin/env python

import random
import math

def convert(a, b):
    return int(a, base=b)
    # res = 0
    # t = 0
    # while a > 0:
    #     res += (a % 10) * base[b][t]
    #     t += 1
    #     a /= 10
    # return res

def sieve(n):
# Compute primes using sieve of Eratosthenes
    x = [1]*n
    x[1] = 0
    for i in range(2, n/2):
        j = 2*i
        while j<n:
            x[j] = 0
            j = j+i
    return x

def find_divisor(a):
    for i in range(primes):
        if prime[i] >= a:
            return -1
        if a % prime[i] == 0:
            return prime[i]
    for i in range(prime[-1]+1, int(math.sqrt(a))+2):
        if a % i == 0:
            return i
    return -1

Limit = 100000
isPrime = sieve(Limit)
isPrime[0] = 0
prime = []
for i in range(Limit):
    if isPrime[i]:
        prime += [i]
primes = len(prime)

# base = [[],[]]
# for b in range(2, 11):
#     a = [1]
#     for i in range(1, 32):
#         a += [a[i-1] * b]
#     base += [a]

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d:" % Case
    t = map(int, raw_input().split(" "))
    n = t[0]
    j = t[1]

    # L = int("1" + "0"*(n-1), base=2)
    # R = int("1"*n, base=2)
    L = 0
    R = int("1"*(n-2), base=2)

    visit = {}

    cnt = 0
    while cnt < j:
        cur = bin(random.randint(L, R))[2:]
        while cur in visit:
            cur = bin(random.randint(L, R))[2:]
        visit[cur] = True
        cur = "1" + "0" * ((n-2) - len(cur)) + cur + "1"
        # cur = "1001100110110000"

        divisors = []
        flag = True
        # print cur,
        for b in range(2, 11):
            divisor = find_divisor(convert(cur, b))
            # print convert(cur, b),
            if divisor != -1:
                divisors += [divisor]
            else:
                # print cur, "FAILED", b, convert(cur, b)
                flag = False
                break
        # print
        if flag:
            print cur, " ".join([ str(x) for x in divisors])
            cnt += 1
