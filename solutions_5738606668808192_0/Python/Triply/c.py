
import numpy as np
import math


# small
N = 16
J = 50
OUTPUT = 'C-small.out'

# big
# N = 32
# J = 500
# OUTPUT = 'C-big.out'

# find some primes
# max_int = 10**9
# is_prime = np.ones(max_int+1, dtype=np.bool)
# primes = []
# # primes_set = set()
# for i in xrange(2, int(math.sqrt(max_int))+1):
#     if is_prime[i]:
#         # primes.append(i)
#         # primes_set.add(i)
#         is_prime[np.arange(2*i, max_int+1, i)] = False
# for i in xrange(2, max_int+1):
#     if is_prime[i]:
#         primes.append(i)
# with open('primes.txt', 'w') as fout:
#     for p in primes:
#         fout.write('{}\n'.format(p))


# read primes
primes = []
with open('primes.txt', 'r') as fin:
    for line in fin:
        primes.append(int(line))

def get_divisor(k):
    for p in primes:
        if p >= k:
            return False
        elif k % p == 0:
            return p
    return False


def check_coin(coin):
    rep = '{0:b}'.format(coin)
    divisors = []
    for base in xrange(2, 11):
        number = int(rep, base)
        d = get_divisor(number)
        if d:
            divisors.append(d)
        else:
            return False
    return rep, divisors


coins = xrange(2**(N-1)+1, 2**N, 2)
with open(OUTPUT, 'w') as fout:
    fout.write('Case #1:\n')
    found_jamcoins = 0
    for coin in coins:
        check_result = check_coin(coin)
        if check_result:
            rep, divisors = check_result
            found_jamcoins += 1
            fout.write('{} {}\n'.format(rep, ' '.join(map(str, divisors))))
            if found_jamcoins >= J:
                break


