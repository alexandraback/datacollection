from __future__ import print_function
import sys

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

    for i in range(2, 10000):
        if n % i == 0:
            return False

    return True

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

def get_factor(num):
    cand = 2
    while num % cand > 0:
        cand += 1

    return cand

def main():
    N = 32
    J = 500

    print('Case #1:')

    cur_candidate = 1 << (N - 1)
    num_found = 0
    while (num_found < J):
        if cur_candidate % 2 == 0:
            cur_candidate += 1
            continue
        
        binary_rep = "{0:b}".format(cur_candidate)

        cur_candidate += 1

        numbers = []
        for i in range(2, 11):
            numbers.append(int(binary_rep, i))
            
        none_prime = True
        for number in numbers:
            if is_prime(number):
                none_prime = False
                break

        if not none_prime:
            cur_candidate += 1
            continue

        sys.stdout.write(binary_rep)

        for number in numbers:
            sys.stdout.write(' ')
            sys.stdout.write(str(get_factor(number)))

        num_found += 1
            
        sys.stdout.write('\n')

main()
