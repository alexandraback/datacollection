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


case_number = readint()
for case in range(case_number):
    N, J = readlinearray()
    print("Case #1:")
    i = 2**(N - 1) + 1
    while J > 0:
        s = bin(i)[2:]
        divisors = []
        for j in range(2, 11):
            k = int(s, base=j)
            d = get_min_divisor(k)
            if d < k:
                divisors.append(d)
            else:
                break
        else:
            print('%s %s' % (s, ' '.join(map(str, divisors), )))
            J -= 1
        i += 2
