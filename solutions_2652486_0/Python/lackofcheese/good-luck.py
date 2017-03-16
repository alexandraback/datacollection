from __future__ import print_function, division
try:
    range = xrange
except NameError:
    pass
import os
import sys

import collections
import functools
import itertools as it
import numpy as np # See http://www.numpy.org/
import gmpy2 as g2 # See https://code.google.com/p/gmpy/
import random
#import networkx as nx # See http://networkx.github.io/

# MY MODULES
sys.path.append(os.path.join(os.environ['GOOGLE_DRIVE'], 'Coding', 'GCJ'))
import proc

def toks_line(f, fun=lambda x: x):
    return [fun(k) for k in f.readline().strip().split()]

def process_first(f):
    num_cases = int(f.readline())
    other_data = None
    return num_cases, other_data

def process_case(f, f_out, case_no, other_data):
    r, n, m, k = toks_line(f, int)
    data = []
    for i in range(r):
        data.append(toks_line(f, int))
    guesses = solve(n, m, np.array(data, dtype=object))
    print("Case #{}:".format(case_no), file=f_out)
    for g in guesses:
        print(''.join(str(n) for n in g), file=f_out)

def solve(n, m, data):
    rng = range(2, m+1)

    base_prods = {}
    counts = collections.defaultdict(collections.Counter)
    all_prods = set() 
    for nums in it.product(rng, repeat=n):
        nums = tuple(sorted(nums))
        base_prods[nums] = 1
        for sl in range(0, n+1):
            for comb in it.combinations(nums, sl):
                product = np.prod(comb)
                counts[product][nums] += 1

    #print(base_prods)
    guesses = []
    for prods in data:
        c2 = base_prods.copy()
        for p in prods:
            cp = counts[p]
            for set_, count in list(c2.items()):
                if set_ not in cp:
                    del c2[set_]
                else:
                    c2[set_] *= cp[set_]
        mxv = max(c2.values())
        all_keys = [k for k in c2 if c2[k] == mxv]
        guesses.append(random.choice(all_keys))
    return guesses

if __name__ == '__main__':
    proc.process_input(process_case, process_first)
