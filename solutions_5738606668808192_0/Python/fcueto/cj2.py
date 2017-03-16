from __future__ import print_function
# Fernando Gonzalez del Cueto
# Google Code Jam 2016
#
# Problem B - Revenge of the Pancakes

import numpy as np
import pyprimes
import fractions
from operator import mul
from itertools import combinations
from collections import OrderedDict as odict

# fname_in = r"test.in"
fname_in = r"small.in"
#fname_in = r"B-small-attempt0.in"
#fname_in = r"B-large.in"

fname_out = fname_in.replace('.in', '.out')

fin = open(fname_in, 'r')
fout = open(fname_out, 'w')

list_of_primes = [2, 3, 5]

def gcd(l):
    if len(l)==2:
        return fractions.gcd(l[0],l[1])
    else:
        return fractions.gcd(l[0], gcd(l[1:]))

def possible_divisors(primes):
    n = len(primes)

    s = set(primes)
    for k in range(2, n):
        l = [reduce(mul,comb,1) for comb in combinations(primes, k)]
        s.update(l)
    return s

def prod(l):
    return reduce(mul, l, 1)

class JamCoin(object):

    def __init__(self, s):
        self.s = s

    def is_valid(self):
        self.d = odict()
        res = True
        for base in range(2,11):
            kb = self.inbase(base)
            if pyprimes.isprime(kb):
                res = False
                break
            else:
                self.d[base] = pyprimes.factorise(kb).next()[0]
        return res

    def inbase(self, k):
        return int(self.s, base=k)

    def __repr__(self):
        return self.s

    def __str__(self):
        return self.s

    def return_divisors(self):
        return [self.d[k] for k in self.d.keys()]


def gen_coins(length, n_coins):

    n2 = length-2
    max_num = int('1'*n2, base=2)

    counter = 0
    for k in xrange(max_num+1):

        b = bin(k)[2:]
        b = '0' * (n2 - len(b)) + b
        coin_s = '1' + b + '1'
        j = JamCoin(coin_s)
        if j.is_valid():
            counter += 1
            yield j

        if counter == n_coins:
            break


n_cases = int(fin.readline().strip())
for case_j in range(1, n_cases+1):

    print('Case #1:')
    fout.write('Case #1:\n')
    N, J = [int(s) for s in fin.readline().split()]
    for coin in gen_coins(N, J):
        divisors = coin.return_divisors()
        line_out =("%s" % coin) + ' ' + ' '.join([str(d) for d in divisors]) + '\n'
        print(line_out, end='')
        fout.write(line_out)



fin.close()
fout.close()

