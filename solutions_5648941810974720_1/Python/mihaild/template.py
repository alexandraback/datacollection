import numpy

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

WORDS = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
letters = ''.join(sorted(set(''.join(WORDS))))
matrix = numpy.array([[w.count(l) for w in WORDS] for l in letters], dtype='int32')

case_number = readint()
for case in range(case_number):
    s = input()
    b = numpy.array([s.count(l) for l in letters], dtype='int32')
    q = numpy.linalg.lstsq(matrix, b)
    #print(q[0])
    #print(list(map(int, q[0])))
    print("Case #%s: %s" % (case + 1, ''.join(str(i) * int(round(q[0][i])) for i in range(10)), ))
