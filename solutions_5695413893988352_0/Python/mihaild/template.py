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


def enlen(x, n):
    x = str(x)
    return '0' * (n - len(x)) + x


def check(x, T):
    x = enlen(x, len(T))
    return all(x[i] == T[i] or T[i] == '?' for i in range(len(T)))

case_number = readint()
for case in range(case_number):
    C, J = readlinearray(str)
    best = (99999, -9999)
    for i in range(10 ** len(C)):
        if not check(i, C):
            continue
        for j in range(10 ** len(J)):
            if not check(j, J):
                continue
            if abs(i - j) < abs(best[0] - best[1]) or abs(i - j) == abs(best[0] - best[1]) and (i < best[0] or i == best[0] and j < best[1]):
                best = (i, j)
    print("Case #%s: %s %s" % (case + 1, enlen(best[0], len(C)), enlen(best[1], len(C))))
