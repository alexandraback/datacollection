import math
def readint():
    return int(raw_input())
def readfloat():
    return float(raw_input())
def readarray(N, foo=raw_input):
    return [foo() for i in xrange(N)]
def readlinearray(foo=int):
    return map(foo, raw_input().split())

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
for case in xrange(case_number):
    a, b = raw_input().split('/')
    a = int(a)
    b = int(b)
    g = gcd(a, b)
    a /= g
    b /= g
    if not is_pow2(b):
        print "Case #%s: %s" % (case + 1, 'impossible')
    else:
        while a > 1:
            a = a // 2
            b = b // 2
        t = 1
        while 2**t < b:
            t += 1
        print "Case #%s: %d" % (case + 1, t)
