#! /usr/bin/env python2

# multiprocessing (per base) variant

import sys
from math import ceil, floor, sqrt
import multiprocessing

from gmpy2 import is_prime


n = int(sys.stdin.readline().strip())

def jamcoin_divisor_base(args):
    jc, b = args
    c = int(jc, b)
    if c in [0, 1]:
        return False
    # for a in xrange(int(floor(sqrt(c))), 1, -1):
    for a in xrange(2, int(ceil(sqrt(c)))):
        if c % a == 0:
            return a
    return False

mpool = multiprocessing.Pool(4)

def jamcoin_verify(s):
    '''
    Return False if string s does NOT represent a jamcoin,
    otherwise (if it IS), return a list of divisors in bases 2 to 10
    '''
    if not (s[0] == s[-1] == '1'):
        return False
    for base in range(2, 10+1):
        if is_prime(int(s, base)):
            return False
    r = []
    r = mpool.map(jamcoin_divisor_base, [(s, x) for x in range(2, 10+1)])
    if False in r:
        return False
    return r

def solve(a):
    N, J = a
    j = 0
    for i in xrange(2**(N-2)):
        x_bin_str_middle = bin(i)[2:]
        jcoin = '1' + '0'*(N-len(x_bin_str_middle)-2) + x_bin_str_middle + '1'
        r = jamcoin_verify(jcoin)
        if r:
            print("{} {}".format(jcoin, " ".join(str(x) for x in r)))
            j += 1
            if j == J:
                return

for i in range(n):
    line = sys.stdin.readline().strip()
    a = [ int(x) for x in line.split(" ") ]
    print("Case #{}:".format(i+1))
    solve(a)

