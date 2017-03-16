import numpy
import random

from pdb import set_trace as debugger

fi = open('sample.in')
# fi = open('small2.in')
fi = open('D-small-attempt0.in', 'r')
fo = open('dresult.out', 'w')

import itertools
import numpy as np
from pdb import set_trace as debugger

T = int(fi.readline())

def analyse(K, C):
    _list_fractile(K, C)


def _list_fractile(K, max_complexity):
    P = pow(2, K)
    original_fractile = np.empty((P, K), dtype='i4') # complexity = 1
    original_fractile.fill(0)

    fractiles = dict()
    for i in range(P):
        bin_i = bin(i)[2:]
        j = 0
        while(j < len(bin_i)):
            original_fractile[i][-j-1] =int(bin_i[-j-1])
            j += 1

    # print original_fractile

    fractiles[1] = original_fractile

    for complexity in range(2, max_complexity + 1):
        original_fractile = fractiles[complexity - 1]

        L = pow(K, complexity)
        new_fractiles = np.empty((P, L), dtype='i4')
        new_fractiles.fill(0)

        for r in range(P):
            original_r = r
            for c in range(L):
                original_c = c / K
                if original_fractile[original_r][original_c] == 1:
                    new_fractiles[r][c] = 1
                    # print '[%s][%s] = %s' % (r, c , new_fractiles[r][c])
                else:
                    # print 'index = %s' % (c % K)
                    val =  original_fractile[r][c % K]
                    # print '[%s][%s] = %s' % (r, c % K, val)
                    new_fractiles[r][c] = val

            # print new_fractiles

        fractiles[complexity] = new_fractiles

    # analyse all fractiles
    print "### Complexity for K = %s: " % K
    for complexity, fractile in fractiles.iteritems():

        L = pow(K, complexity)
        count_one = list()
        print "    %s" % np.sum(fractile, axis=0)


def solve_for_small(K, C):
    return ' '.join([str(v) for v in range(1, K+1)])


for t in range(1, T+1):
    K, C, S = [int(c) for c in fi.readline().strip().split(' ')]
    # analyse(K, C)

    output_val = solve_for_small(K, C)
    fo.write('Case #%i: %s\n' % (t, output_val))

