from itertools import imap
from multiprocessing import Pool

raw_input()


def largest_prime_factor(n):
    for p in _known_primes:
        if not n % p:
            return p
    return False


# https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test
def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, 2 ** i * d, n) == n - 1:
            return False
    return True  # n  is definitely composite


def is_prime(n, _precision_for_huge_n=32):
    if n in _known_primes or n in (0, 1):
        return True
    if any((n % p) == 0 for p in _known_primes):
        return False
    d, s = n - 1, 0
    while not d % 2:
        d, s = d >> 1, s + 1
    # Returns exact according to http://primes.utm.edu/prove/prove2_3.html
    if n < 1373653:
        return not any(_try_composite(a, d, n, s) for a in (2, 3))
    if n < 25326001:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5))
    if n < 118670087467:
        if n == 3215031751:
            return False
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7))
    if n < 2152302898747:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11))
    if n < 3474749660383:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13))
    if n < 341550071728321:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13, 17))
    # otherwise
    return not any(_try_composite(a, d, n, s)
                   for a in _known_primes[:_precision_for_huge_n])

_known_primes = [2, 3]
_known_primes += [x for x in range(5, 1000, 2) if is_prime(x)]


def is_jamcoin(x):
    x = bin(x)[2:]
    if x[0] != '1' or x[-1] != '1': return
    for base in range(2, 11):
        n = int(x, base)
        if is_prime(n): return
    r = []
    for base in range(2, 11):
        n = int(x, base)
        v = largest_prime_factor(n)
        if not v: return
        r.append(v)
    return [x] + r


n, j = map(int, raw_input().split(' '))

results = []

for divs in imap(is_jamcoin, xrange((1 << (n - 1)), 1 << n)):
    if not divs: continue
    results.append(divs)
    # print len(results), divs[0]
    if len(results) >= j: break

print "Case #1:"
for r in results:
    print ' '.join(str(x) for x in r)
