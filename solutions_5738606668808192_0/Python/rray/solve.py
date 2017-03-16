import random
import sys

def find_divisor(n):
    for i in xrange(3, int(n ** 0.5)):
        if n%i == 0:
            return i
    return None

def verify(coin):
    base_order = [2, 3, 5, 7, 4, 6, 8, 9, 10]
    divisor_db = {}
    for base in base_order:
        divisor = find_divisor(int(''.join(map(str, coin)), base))
        if divisor is None:
            return None
        divisor_db[base] = divisor
    return [divisor_db[i] for i in xrange(2,11)]

def mod_coin(coin, m):
    index = len(coin)-2
    while index > 0:
        coin[index] = m%2
        m /= 2
        index -= 1

def mine(n, j):
    coin = [0] * n
    coin[0] = 1
    coin[-1] = 1
    coins = {}
    for i in xrange(2, 2**(n-2)):
        mod_coin(coin, i)
        divisors = verify(coin)
        if divisors is not None:
            coins[''.join(map(str, coin))] = divisors
            j -= 1
        if j == 0:
            break
    return coins

def main():
    t = int(raw_input())
    for i in xrange(t):
        n, j = map(int, raw_input().split())
        coins = mine(n, j)
        print "Case #{}:".format(i+1)
        for key in coins:
            print "{} {}".format(key, ' '.join(map(str, coins[key])))

if __name__ == '__main__':
    main()


"""
a = gen_primes(2**16 + 1, 2**16 + 1 + 100000)
b = map(lambda x: bin(x)[2:], a)

primes_2 = set()
primes_3 = set()
primes_6 = set()

for i in b:
    if is_probable_prime(int(i, 2), 20):
        primes_2.add(i)
    if is_probable_prime(int(i, 5), 20):
        primes_3.add(i)
    if is_probable_prime(int(i, 10), 20):
        primes_6.add(i)

print "primes_2", len(primes_2)
print "primes_3",len(primes_3)
print "primes_6",len(primes_6)
print "primes_2x6",len(primes_2.intersection(primes_6))
print "primes_3x6",len(primes_3.intersection(primes_6))
print "primes_2x3x6",len(primes_2.intersection(primes_3).intersection(primes_6))
print "primes_6-3",len(primes_6 - primes_3)
print "primes_6-2",len(primes_6 - primes_2)
print "primes_6-2&3",len(primes_6 - primes_2.union(primes_3))
print "primes_6-2.3",len(primes_6 - primes_2.intersection(primes_3))
"""
