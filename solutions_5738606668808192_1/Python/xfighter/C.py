#! /usr/bin/python

import sys

primes = []

def GeneratePrimes(N):
    sieve = [True for i in range(0, N + 1)]
    sieve[0] = False
    sieve[1] = False
    for i in range(2, N + 1):
        if not sieve[i]:
            continue
        primes.append(i)
        for j in range(i * i, N + 1, i):
            sieve[j] = False
    return primes

def GetDivisor(N):
    for prime in primes:
        if N % prime == 0:
            return prime
    return -1

def main(argv):
    GeneratePrimes(10000)
    sys.stdout.write("Case #1:\n")
    J = 500
    generated = 0;
    curr = (1 << 30) - 1;
    # curr = 1
    while (curr > 0):
        s = "1{0:b}1".format(curr)
        # s = "1111111111110101"
        curr = curr - 1
        divisors = []
        for b in range(2, 11):
            cn = int(s, b)
            divisor = GetDivisor(cn)
            if divisor != -1:
                divisors.append(divisor)
            else:
                # print "Not divisble in b %d, num=%d" % (b, cn)
                break
        if len(divisors) == 9:
            generated = generated + 1
            sys.stdout.write(s)
            for divisor in divisors:
                sys.stdout.write(" %d" % (divisor))
            sys.stdout.write("\n")
            if generated == J:
                exit()


if __name__ == '__main__':
    main(sys.argv)
