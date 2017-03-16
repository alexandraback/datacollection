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
    N = readint()
    a = readarray(N, lambda: input().split())
    c = 0
    for i in range(2**N):
        fo = set()
        so = set()
        fp = set()
        sp = set()
        tt = 0
        for j in range(N):
            if i & (1 << j):
                fo.add(a[j][0])
                so.add(a[j][1])
            else:
                tt += 1
                fp.add(a[j][0])
                sp.add(a[j][1])
        if fp.issubset(fo) and sp.issubset(so):
            c = max(c, tt)
    print("Case #%s: %d" % (case + 1, c))
