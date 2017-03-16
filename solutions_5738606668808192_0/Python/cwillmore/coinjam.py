import sys
import random
import math

fp = open(sys.argv[1])
def readline():
    return fp.readline().strip()

# small: n = 16, j = 50
# large: n = 32, j = 500

def may_be_prime(p):
    # euler's little theorem: if p is prime then a^(p - 1) = 1 (mod p)
    # we're only interested in composite numbers here so false primes (i.e.
    # carmichael numbers) are OK
    for i in xrange(20):
        a = random.randint(1, p - 1)
        if pow(a, p - 1, p) != 1:
            return False
    return True

def try_generate_jamcoin(n):
    s = '1' + ''.join(random.choice('01') for i in xrange(n - 2)) + '1'
    for base in xrange(2, 11):
        if may_be_prime(int(s, base)):
            return None
    # OK, let's try to find factors
    factors = []
    for base in xrange(2, 11):
        ns = int(s, base)
        factor = None
        for j in xrange(2, 100000):
            if ns % j == 0:
                factor = j
                break
        if factor is None:
            return None # you tried :(
        factors.append(factor)
    return (s, factors)

def generate_jamcoin(n):
    result = None
    while result is None:
        result = try_generate_jamcoin(n)
    return result

def solve(n, j):
    # n = length of jamcoin
    # j = number of jamcoins to generate
    # return jamcoin, followed by divisors in decimal

    # the first and last digits of the jamcoin must be 1
    for i in xrange(j):
        coin, proof = generate_jamcoin(n)
        print "%s %s" % (coin, ' '.join(str(x) for x in proof))

if __name__ == '__main__':
    num_cases = int(readline())
    for i in xrange(num_cases):
        n, j = [int(x) for x in readline().split()]
        print "Case #%d:" % (i + 1)
        solve(n, j)
