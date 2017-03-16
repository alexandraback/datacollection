from random import randrange


small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]


def try_get_first_divisor(n, k):
    i = 2
    while i * i < n and i < k:
        if n % i == 0:
            return i
        i += 1

    return None


# Miller-Rabin
def probably_prime(n, k=100):
    if n < 2:
        return False
    for p in small_primes:
        if n < p * p:
            return True
        if n % p == 0:
            return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True


def solve(N, J):
    n = (1 << (N-1)) + 1
    found = 0
    while found < J:
        is_prime = False
        s = bin(n)[2:]
        factors = []
        for b in xrange(2, 11):
            m = int(s, b)
            d = None
            if not probably_prime(m):
                d = try_get_first_divisor(m, 1e4)
            if not d:
                is_prime = True
                break
            factors.append(d)
        if not is_prime:
            yield s, factors
            found += 1
        n += 2


with open("coin_jam.in") as fin:
    T = int(fin.readline())
    for t in xrange(T):
        N, J = map(int, fin.readline().split())
        print "Case #%d:" % (t+1)
        for result in solve(N, J):
            print result[0], " ".join(map(str, result[1]))
