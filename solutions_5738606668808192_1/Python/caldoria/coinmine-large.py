# Using python because of native support of big integers which makes this easier.

import random
import sys
from math import sqrt, ceil

N = 32;
J = 500;

print "Case #1:"

generated_candidates = set()

def print_coin(coin):
    for b in reversed(coin):
        sys.stdout.write('1' if b == 1 else '0')

def in_base(base, coin):
    sum = 0L;
    for i in range(len(coin)):
        if coin[i]:
            sum += base**i
    return sum

def generate_coin():
    cand = []
    cand.append(1L)
    for i in range(N-2):
        cand.append(random.getrandbits(1))
    cand.append(1L)
    cand = tuple(cand)
    if cand in generated_candidates:
        return generate_coin()
    else:
        generated_candidates.add(cand)
        return cand

def find_divisors(coin):
    divisors = [-1, -1]
    for i in range(2, 11):
        N = in_base(i, coin)
        #limit = int(ceil(sqrt(N)+1))
        limit = int(1e5)
        found = False
        for d in xrange(2, limit):
            if N % d == 0:
                divisors.append(d)
                found = True
                break
        if not found:
            divisors.append(-1)
            return divisors
    return divisors

for j in range(J):

    found = False
    cand = None
    divs = None
    while (not found):
        cand = generate_coin()
        divs = find_divisors(cand)
        found = True
        for i in range(2, 11):
            if divs[i] == -1:
                found = False
                break
    print_coin(cand)
    for d in range(2, 11):
        sys.stdout.write(" {}".format(divs[d]))
        sys.stdout.flush()
    sys.stdout.write("\n")
