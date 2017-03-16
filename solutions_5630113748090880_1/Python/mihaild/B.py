import string
from collections import Counter

def readint():
    return int(input())


def readfloat():
    return float(input())


def readarray(N, foo=input):
    return [foo() for i in range(N)]


def readlinearray(foo=int):
    return list(map(foo, input().split()))


def GCD(a, b):
    while b:
        a, b = b, a % b
    return a


def gen_primes(max):
    primes = [1]*(max+1)
    for i in range(2, max+1):
        if primes[i]:
            for j in range(i+i, max+1, i):
                primes[j] = 0
    primes[0] = 0
    return [x for x in range(2, max+1) if primes[x]]

primes = gen_primes(2**20)


def get_min_divisor(N):
    for p in primes:
        if N % p == 0:
            return p
        if p * p > N:
            return N
    return N


def get(s):
    for l in string.ascii_uppercase[::-1]:
        if l in s:
            return l * s.count(l) + get(s[:s.index(l)]) + ''.join(x for x in s[s.index(l):] if x != l)
    return ''


case_number = readint()
for case in range(case_number):
    N = readint()
    numbers = Counter()
    for i in range(2 * N - 1):
        numbers.update(readlinearray())
    bad = [x for x in numbers if numbers[x] % 2]
    bad.sort()
    print("Case #%d: %s" % (case + 1, ' '.join(map(str, bad))))
