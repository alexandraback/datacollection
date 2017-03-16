def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, 2**i * d, n) == n-1:
            return False
    return True # n  is definitely composite

def is_prime(n, _precision_for_huge_n=16):
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


data = iter(open('C-small-attempt0.in').read().splitlines())
cases = int(next(data))

for case in range(1, cases + 1):
    print "Case #1:"
    N, J = map(int, next(data).split())
    b = 1 << N
    a = (1 << (N - 1)) + 1
    needed = J
    for i in xrange(a, b, 2):
        s = bin(i)[2:]
        ok = True
        for b in range(2, 11):
            x = int(s, b)
            if is_prime(x):
                ok = False
                break
        if ok:
            needed -= 1
            row = [s]
            for b in range(2, 11):
                x = int(s, b)
                for d in xrange(2, int(x**0.5) + 1):
                    if (x % d) == 0:
                        row.append(d)
                        break
            print " ".join(map(str, row))
        if not needed:
            break


    #print "Case #%d: %s" % (case, ans)

