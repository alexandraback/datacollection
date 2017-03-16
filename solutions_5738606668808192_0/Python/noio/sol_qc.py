#! /usr/bin/python

__author__ = 'BJG Association'

### IMPORTS ###
import sys
import numpy as np
import scipy.ndimage as ndi
from itertools import islice, count
from math import sqrt
from pprint import pprint


### FUNCTIONS ###


def schweng(n):
    """ best way to see if n is schweng 
    """
    if n == 1:
        return (False, None)

    # for divisor in islice(count(2), int(sqrt(n)-1)):
    max_divisor = min(200, sqrt(n)-1 )

    for divisor in islice(count(2), max_divisor):
        if n % divisor == 0:
            return (False, divisor)

    return (True, None)



def is_jamcoin_slow(jamcoin):

    print "\nMAYBE JAMCOIN: %s" % jamcoin

    it_is_schweng = False
    all_divisors = []

    for base in xrange(2,11): 
        num_in_base = int(jamcoin, base)

        print "base%s %s" % (base, num_in_base)

        (it_is_schweng, divisor) = schweng(num_in_base)
        
        if it_is_schweng:
            break
        else:
            all_divisors.append(divisor)

    if it_is_schweng:
        return (False, None)
    else:
        print "FOUND A JAMCOIN: %s (%s)" % (jamcoin, all_divisors)
        return (True, all_divisors)
        


def solve(N, J):
    print N, J
    
    all_jamcoins = []

    for i in xrange( 2 ** (N-2) ):

        jamcoin = (['1',] + list(bin(i)[2:].zfill(N - 2)) + ['1',])

        jamcoin = ''.join(jamcoin)

        (is_jamcoin, divisors) = is_jamcoin_slow(jamcoin)
        
        if is_jamcoin: 
            all_jamcoins.append( (jamcoin, divisors ))

            if (len(all_jamcoins) == J):
                break

    return all_jamcoins
        
    
    # for (jamcoin, divisors) in all_jamcoins:
    #     print
    #     print jamcoin
    #     print divisors

    #     for base, div in zip(xrange(2,11), divisors): 
    #         num_in_base = int(jamcoin, base)
    #         print num_in_base, div
        
        # print i, "%s" % jamcoin


### PROCESS INPUT FILE ###

if __name__ == '__main__':
    f = open(sys.argv[1])
    fout = open(sys.argv[1].replace('.in','.out'),'w')

    T = int(f.readline())

    for case in xrange(T):
        (N, J) =  [int(x) for x in f.readline().split()]
        
        all_jamcoins = solve(N, J)
        
        fout.write('Case #%d:\n'%(case+1))

        for (jamcoin, divisors) in all_jamcoins:
            fout.write('%s %s\n' % (jamcoin, " ".join(str(d) for d in divisors)))
