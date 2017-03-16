import math
import functools
import collections
def readint():
    return int(input())
def readfloat():
    return float(input())
def readarray(N, foo=input):
    return [foo() for i in range(N)]
def readlinearray(foo=int):
    return map(foo, input().split())

def gcd(a, b):
    while b:
        a,b = b, a%b
    return a

def gen_primes(max):
    primes = [1]*(max+1)
    for i in range(2, max+1):
        if primes[i]:
            for j in range(i+i, max+1, i):
                primes[j] = 0
    primes[0] = 0
    return [x for x in range(max+1) if primes[x]]

def is_prime(N):
    i = 3
    if not(N % 2):
        return 0
    while i*i < N:
        if not(N % i):
            return 0
        i += 3
    return 1

def is_pow2(x):
    return x == 1 or (x % 2 == 0 and is_pow2(x // 2))


@functools.lru_cache(maxsize=None)
def check_one(c, w):
    if c == w:
        return w
    if c < 2*w:
        return w + 1
    return 1 + check_one(c - w, w)

case_number = readint()
for case in range(case_number):
    R, C, W = readlinearray()
    answer = check_one(C, W) + (R - 1) * C // W
    print("Case #%s: %d" % (case + 1, answer))
