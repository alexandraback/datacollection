

primes = []

for i in range(2, 2**16):
    is_prime = True
    for p in primes:
        if i % p == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(i)

def getFactor(n):
    for p in primes:
        if p >= n:
            break
        if n % p == 0:
            return p
    return 0

def isValid(N):
    s = bin(N)[2:]
    result = []
    for base in range(2, 11):
        m = int(s, base)
        t = getFactor(m)
        if t == 0:
            return False
        result.append(t)
    print s,
    for i in result:
        print i,
    print
    return True

T = input()
for case in range(1, T + 1):
    print "Case #%d:"%case
    N, J = map(int, raw_input().split())
    b = 2 ** (N-1) + 1
    for _ in range(J):
        while True:
            if isValid(b):
                b += 2
                break
            b += 2
