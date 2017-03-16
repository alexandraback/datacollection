from __future__ import division

import os
import sys
import math, random
from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

def exp_modulo(n, exp, div):
    digits = []
    while exp > 0:
        digits.append(exp % 2)
        exp //= 2
    digits = tuple(reversed(digits))
    x = 1
    for digit in digits:
        x = x ** 2
        if digit == 1:
            x *= n
        x %= div
    return x

def is_prime(n, error):
    """
    Uses probabilistic Miller-Rabin primality test to determine whether n is
    prime or composite.

    Arguments:
    n -- number to be tested
    error -- maximum acceptable probability that the result will be wrong
    """
    if n <= 0: raise ValueError("Argument is not a positive integer")
    if n == 1: return False
    if n == 2: return True
    s, d = 0, n - 1
    while d % 2 == 0:
        d //= 2
        s += 1
    assert(2**s * d == n-1 and d % 2 == 1)
    def could_be_prime():
        a = random.randint(1, n-1)
        x = exp_modulo(a, d, n)
        if x == 1: return True
        for r in range(s):
            if x == n-1: return True
            x = x**2 % n
        return False
    # At least 3/4 of numbers are witnesses for compositeness of any n.
    for i in range(int(math.log(1/error, 4))+1):
        if not could_be_prime(): return False
    return True

name = 'C-small-attempt0.in'

class StopError(Exception):
    pass

for i in range(10000):
    n = random.randint(1,1000)
    exp = random.randint(1,1000)
    #div = random.randint(1,1000)
    div = 10**100
    a = exp_modulo(n, exp, div)
    b = (n ** exp) % div
    if a != b:
        print(n, exp, div, a, b)
        raise Exception

def _solve(j, n):
    res = {}
    while True:
        divs = {}
        try:
            t = '1'+''.join(random.choice(['0','1']) for _ in range(n-2))+'1'
            for base in range(2, 11):
                d = int(t, base)
                if is_prime(d, 10**(-10)):
                    raise StopError
                for k in range(2, 10000):
                    if d % k == 0:
                        divs[base] = k
                        break
                if base not in divs:
                    raise StopError
            res[t] = divs
        except StopError:
            pass
        if len(res) == j:
            break
    return res

def solve(j, n):
    res = _solve(j, n)
    assert(len(res) == j)
    for c, divs in res.items():
        print(c, divs)

        for base, div in divs.items():
            assert(int(c, base) % div == 0)
    return '\n' + '\n'.join(c+' '+ ' '.join(map(str, divs.values())) for c, divs in res.items())

#print(solve(50, 16))
#sys.exit(0)

inp_path = '/home/mama/Downloads/%s'%name
if os.path.isfile(inp_path):
    os.system('mv %s .' % inp_path)
inp_file = open(name)
out_file = open('%s.out'%name, 'w')
cases = int(inp_file.readline())
for caseno in range(cases):
    n, j = tuple(map(int, inp_file.readline().split()))
    res = solve(j, n)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()
