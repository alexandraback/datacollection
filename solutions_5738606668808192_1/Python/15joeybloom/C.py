
import sys

NUM_PRIMES = 100000
sieve = [True] * NUM_PRIMES
primes = []

sieve[1] = False
for i in xrange(2,NUM_PRIMES):
    if sieve[i]:
        primes.append(i)
        for j in xrange(i+i, NUM_PRIMES, i):
            sieve[j] = False

def composite(x):
    for p in primes:
        if x>p and x%p == 0:
            return p
    return 0

T = int(raw_input())
NJ = raw_input().split()
N = int(NJ[0])
J = int(NJ[1])
jamcoin = (1<<(N-1)) + 1
factors = [0]*11

sys.stdout.write("Case #1:\n")
jamcoins = 0
while jamcoins < J:
    factors[2] = composite(jamcoin)
    if factors[2] == 0:
        jamcoin += 2
        continue
    good = True
    for i in xrange(3,11):
        val = 0
        for j in xrange(16):
            if jamcoin&(1<<j):
                val += i ** j
        factors[i] = composite(val)
        if factors[i] == 0:
            good = False
            break
    if good:
        sys.stdout.write("{0:b}".format(jamcoin))
        for i in xrange(2,11):
            sys.stdout.write(" {0:d}".format(factors[i]))
        sys.stdout.write("\n")
        jamcoins += 1

    jamcoin += 2

