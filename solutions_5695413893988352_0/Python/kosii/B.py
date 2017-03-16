from itertools import *
from functools import *
from operator import *
from math import *
from collections import Counter

import os
import sys
sys.setrecursionlimit(10000)
os.chdir(os.path.dirname(os.path.realpath(__file__)))

filename = "B-small-attempt0"
result_string = "Case #{}: {}"

def replace_qmark(a, b, prod):
    i = 0
    an = 0
    bn = 0
    for j in a:
        if j == '?':
            an = 10*an + prod[i]
            i += 1
        else:
            an = 10*an + int(j)

    for j in b:
        if j == '?':
            bn = 10*bn + prod[i]
            i += 1
        else:
            bn = 10*bn + int(j)
    return an, bn

def minf(a, b, c):
    aa, bb = replace_qmark(a, b, c)
    return (abs(aa - bb), aa, bb)

def main(input_filename, output_filename):
    with open(input_filename) as input, open(output_filename, 'w') as output:
        T, = nis(input)
        for t in range(T):
            a, b = sis(input)
            nqa, nqb = Counter(a).get('?', 0), Counter(b).get('?', 0)
            # print a, b
            # print nqa, nqb
            comb = [range(10)] * (nqa + nqb)
            # print comb
            res = min((c for c in product(*comb)), key=lambda c: minf(a, b, c))
            resa, resb = replace_qmark(a,b,res)
            res = ("%0" + str(len(a)) + "d %0" + str(len(b))+ "d") % (resa, resb)
            # res = None
            w(output, t, res)

def w(output, t, res):
    print(result_string.format(t+1, res))
    output.write(result_string.format(t+1, res)+'\n')

def nis(input):
    return map(int, input.readline().split())

def sis(input):
    return input.readline().split()

def integer_sqrt(i):
    """return tuple (s, b), where b is true if and only if i is a perfect square
    and s is the integer square root
    """
    if not i: return 0
    if i < 0: raise ValueError("cannot calculate square root of negative")
    def n(xn):
        return (xn + i/xn)/2
    xn, xnp, xnpp = i, n(i), n(n(i))
    while xn != xnpp:
        xn, xnp, xnpp = xnp, xnpp, n(xnpp)
    return min(xnp, xnp)

class Memoize(object):
    def __init__(self, f):
        self.f = f
        self.memory = {}
    def __call__(self, *args, **kwargs):
        if (tuple(args), tuple(kwargs.items())) in self.memory:
            return self.memory[(tuple(args), tuple(kwargs.items()))]
        else:
            val = self.f(*args, **kwargs)
            self.memory[(tuple(args), tuple(kwargs.items()))] = val
            return val

def inversion_count(seq):
    if len(seq) < 2:
        return seq, 0
    l = len(seq)/2
    seq1, c1 = inversion_count(seq[:l])
    seq2, c2 = inversion_count(seq[l:])
    inv = 0
    seq = []
    while seq1 or seq2:
        if not seq1:
            seq += seq2
            seq2 = []
        elif not seq2:
            seq += seq1
            seq1 = []
        else:
            e1 = seq1[0]
            e2 = seq2[0]
            if e1 > e2:
                inv += len(seq1)
                seq.append(e2)
                seq2 = seq2[1:]
            else:
                seq.append(e1)
                seq1 = seq1[1:]
    return seq, inv + c1 + c2


if __name__ == '__main__':
    input_filename = "{}.in".format(filename)
    output_filename = "{}.out".format(filename)
    main(input_filename, output_filename)
