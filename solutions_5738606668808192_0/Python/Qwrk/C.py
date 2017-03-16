def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, 2 ** i * d, n) == n - 1:
            return False
    return True  # n  is definitely composite


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


# -----

def to_decimal(x, b):
    e, r = 1, 0
    while x != 0:
        r += (x % 10) * e
        e *= b
        x //= 10
    return r


# -----

def find_divisor(x):
    i = 2
    while i * i <= x:
        if x % i == 0: return i
        i += 1


if __name__ == "__main__":
    print("Case #1:")
    count = 0
    for i in range(0, 2 ** 14):
        v = int('1' + str(bin(i)[2:]).zfill(14) + '1')
        d = [to_decimal(v, b) for b in range(2, 11)]
        if all(not is_prime(x) for x in d):
            count += 1
            print(v, *list(map(find_divisor, d)))
        if count == 50:
            break

