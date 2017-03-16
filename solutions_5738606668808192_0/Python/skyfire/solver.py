#!python

import primefac
import random

n = 32
j = 500

print 'Case #1:'

for _ in xrange(j):

    v = '1'

    while True:
        v = '{0:b}'.format(random.randint(2**(n-1), 2**n-1)|1)

        valid = True

        for radix in xrange(2, 11):
            x = int(v, radix)
            factors = list(primefac.primefac(x))
            if len(factors) == 0:
                valid = False
                break
            d = factors[0]
            if d == 1 or d == x:
                valid = False
                break

        if valid:
            break;

    print v,

    for radix in xrange(2, 11):
        print list(primefac.primefac(int(v, radix)))[0],

    print
