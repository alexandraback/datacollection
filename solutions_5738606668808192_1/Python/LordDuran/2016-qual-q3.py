# from __future__ import division
from pprint import pprint
import time
import random

inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

# Miller-rabin code from https://rosettacode.org/wiki/Miller-Rabin_primality_test#Python
# Licensed under GNU FDL http://www.gnu.org/licenses/fdl.html

def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, 2**i * d, n) == n-1:
            return False
    return True # n  is definitely composite
 
def is_prime(n, _precision_for_huge_n=16):
    if n in _known_primes or n in (0, 1):
        return True
    if any((n % p) == 0 for p in _known_primes):
        return False
    d, s = n - 1, 0
    while not d % 2:
        d, s = d >> 1, s + 1
    if n < 1373653: 
        return not any(_try_composite(a, d, n, s) for a in (2, 3))
    if n < 25326001: 
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5))
    if n < 118670087467: 
        if n == 3215031751: 
            return False
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7))
    if n < 2152302898747: 
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11))
    if n < 3474749660383: 
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13))
    if n < 341550071728321: 
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13, 17))
    # otherwise
    return not any(_try_composite(a, d, n, s) 
                   for a in _known_primes[:_precision_for_huge_n])
 
_known_primes = [2, 3]
print 'Calculating primes'
_known_primes += [x for x in range(5, 10000000, 2) if is_prime(x)]
print 'Finished primes'

def do_case(ncase):
    N, J = parse_line()
    jamcoins = {}
    print 'Creating %d jamcoins of length %d' % (J, N)
    while len(jamcoins) < J:
        b = random.randint(0, 2**32-1)
        bb = bin(b).replace("L","").replace("0b","")
        bb = bb.rjust(32, '0')
        jc = '1' + bb[:N-2] + '1'
        factors = [-1]*9
        all_comp = False
        nums = [-1]*9
        for c in xrange(2, 11):
            num = int(jc, c)
            if is_prime(num):
                break
            nums[c-2] = num
        else:
            all_comp = True
        if not all_comp:
            continue
        needed_factors = 9
        for p in _known_primes:
            for i, num in enumerate(nums):
                if num%p == 0:
                    if factors[i] == -1:
                        factors[i] = p
                        needed_factors -= 1
            if needed_factors <= 0:
                break
        if needed_factors > 0:
            continue
        assert -1 not in factors
        jamcoins[jc] = factors
        print len(jamcoins), J

    print >>outputfile, out_s % (ncase, '')
    for c,v in jamcoins.iteritems():
        print >>outputfile, str(c) + ' ' + ' '.join(str(n) for n in v)

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    