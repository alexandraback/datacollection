import sys

def BaseNToBase10(base, s):
    N = len(s)
    base_10 = 0
    for i in xrange(N):
        if s[i] == '1':
            base_10 += pow(base, N - i - 1)
    return base_10

def ComputePrimes(N):
    is_prime = [ True for i in xrange(N) ]
    is_prime[0] = False
    is_prime[1] = False
    primes = []
    for i in xrange(2, N):
        if not is_prime[i]:
            continue
        primes.append(i)
        j = 2 * i
        while True:
            if j >= N:
                break
            is_prime[j] = False
            j += i
    return primes

primes = ComputePrimes(100)

def ComputeNonTrivialDivisor(d, base):
    global primes
    for p in primes:
        if d % p == 0 and p != base:
            return p
    return -1

test_cases = int(sys.stdin.readline())
N, J = [int(i) for i in sys.stdin.readline().split()]

c = "1" + "0" * (N - 2) + "1"
i = BaseNToBase10(2, c)

res = []

while len(res) < J:
    ok = True
    s = "{0:b}".format(i)
    divisors = []
    for base in xrange(2, 11):
        d = BaseNToBase10(base, s)
        divisor = ComputeNonTrivialDivisor(d, base)
        if divisor < 0:
            ok = False
            break
        else:
            divisors.append("%d" % divisor)
    if ok:
        res.append([s, divisors])
    i += 2

print("Case #1:")
for r in res:
    res = r[0] + " " + " ".join(r[1])
    print(res)
