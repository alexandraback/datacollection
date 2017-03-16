#!/usr/bin/python
import itertools
import math
import sys

BOUNDARY = 1 << 17
used = list(itertools.repeat(True, BOUNDARY))
primes = []

for i in xrange(2, len(used)):
    if used[i]:
        primes.append(i)
        x = i
        while x < BOUNDARY:
            used[x] = False
            x += i


def get_divisor(n):
    for x in primes:
        if x >= n:
            return None

        if n % x == 0:
            return x

    return None


fl = open(sys.argv[1])
fl.readline()

bits, samples = map(int, fl.readline().split())

print 'Case #1:'

number = (1 << (bits - 1)) + 1

while samples > 0:
    ans = ["{0:b}".format(number)]

    for base in range(2, 11):
        nmbr = number
        mult = 1
        n = 0

        while nmbr > 0:
            if nmbr % 2 == 1:
                n += mult
            nmbr /= 2
            mult *= base

        #print n
        divisor = get_divisor(n)
        if not divisor:
            break
        else:
            ans.append(str(divisor))

    if len(ans) == 10:
        samples -= 1
        print ' '.join(ans)

    number += 2
