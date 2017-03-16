#! /usr/bin/env python

import random
import math

def convert(a, b):
    return int(a, base=b)

# def isPrime(p):
#     a = random.choice(prime[:25])
#     a**(p-1)

# def quick(a, b, m):
#     a = a % m
#     t = a
#     res = 0
#     while b > 0:
#         if b % 2:
#             res += t;

def find_divisor(a):
    for i in range(primes):
        if prime[i] >= a:
            return -1
        if a % prime[i] == 0:
            return prime[i]
    # i = prime[-1]+1
    # while i < int(math.sqrt(a))+2:
    #     if a % i == 0:
    #         return i
    #     i += 1
    return -1

prime = map(int, open("prime.list").read().split(" "))
primes = len(prime)

out = open("out1.txt", "w")
T = int(raw_input())
for Case in range(1, T+1):
    out.write("Case #%d:" % Case + '\n')
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
            out.write(str(cur) + " " + " ".join([ str(x) for x in divisors]) + '\n')
            cnt += 1
            print "FOUND", cnt, cur
out.close()
