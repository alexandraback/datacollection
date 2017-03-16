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


case_number = readint()
for case in range(case_number):
    K, C, S = readlinearray()
    if K > C * S:
        print("Case #%s: IMPOSSIBLE" % (case + 1, ))
    else:
        numbers = []
        for d in range(0, K, C):
            c = 0
            for d1 in range(d, min(d + C, K)):
                c = c * K + d1
            numbers.append(c + 1)
        print("Case #%s: %s" % (case + 1, ' '.join(map(str, numbers))))
