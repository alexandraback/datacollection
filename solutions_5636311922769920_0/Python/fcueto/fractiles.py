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
import stopit


#fname_in = r"test.in"
fname_in = r"D-small-attempt0.in"
#fname_in = r"D-large.in"

fname_out = fname_in.replace('.in', '.out')

fin = open(fname_in, 'r')
fout = open(fname_out, 'w')

def myfun(k,c):

    if c==1:
        l2 = range(1,k+1)
    else:
        l1 = myfun(k, c-1)
        l2 = [ (elem + k*j ) for (j, elem) in enumerate(l1)]
    return l2

n_cases = int(fin.readline().strip())
for case_j in range(1, n_cases+1):

    k, c, s = [int(i) for i in fin.readline().split()]

    if k==s:

        result = myfun(k,c)
        result_str = ' '.join([str(elem) for elem in result])
    else:
        result_str = 'undecided. That is not for small problem'

    line_out = "Case #%i: %s" % (case_j, result_str) + '\n'
    print(line_out, end='')
    fout.write(line_out)



fin.close()
fout.close()
