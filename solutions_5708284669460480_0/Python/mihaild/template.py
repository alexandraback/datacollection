import math
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


case_number = readint()
for case in range(case_number):
    k, l, s = readlinearray()
    K = input()
    S = input()
    n = 0
    for i in range(l - 1, 0, -1):
        #print((i, S[:i], S[-i:]))
        if S[:i] == S[-i:]:
            n = i
            break
    a = l - n
    b = n
    #print(a, b)
    max_count = 1 + (s - l) // a
    if not all(c in K for c in S):
        ans = 0.0
    else:
        q = collections.Counter(K)
        prob = 1.0
        for c in S:
            prob *= q[c] / k
        e = prob * (s - l + 1)
        ans = max_count - e
    #print(S, s, max_count)
    print("Case #%s: %f" % (case + 1, ans))
