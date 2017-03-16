from itertools import *
from functools import *
from operator import *
from math import *
from collections import Counter

import os
os.chdir(os.path.dirname(os.path.realpath(__file__)))

filename = "D-small-attempt8"
result_string = "Case #{}: {}"

# def f(X,R,C):
#     R, C = min(R, C), max(R, C)
#     if not (((R*C)%X == 0) and (R*C >= X)):
#         return False
#     if X == 1:
#         return True
#     if X == 2:
#         return (R, C) in [(1, 4), (2, 3), (2, 2), (2, 4), (3, 4), (4, 4)]
#         return True
#     if X == 3:
#         return (R, C) in [(2, 3), (3, 3), (3, 4)]
#         # return R >= 2 and C >= 2
#     if X == 4:
#         return (R, C) in [(3, 4), (4, 4)]
#         return R > 2 and C > 2
#     raise ValueError("wtf {} {} {}".format(X, R, C))


def main(input_filename, output_filename):
    with open(input_filename) as input, open(output_filename, 'w') as output:
        T, = nis(input)
        for t in range(T):
            X, R, C = nis(input)
            res = True
            print X, R, C
            if X > 6:
                print "too much X"
                res = False
            if ceil(X/2.0) > min(R,C):
                print "too much X for R or C"
                res = False
            if (X > 3 and ((min(C, R) <= X/2) if (X%2==0) else (min(C, R) <= X/2+1))):
                print "kukac szabaly"
                res = False
            if ((R * C) % X):
                print "not divisible"
                res = False
            if (R * C / X < 1):
                print "not enough place"
                res = False
            # assert res == f(X, R, C)
            if res:
                w(output, t, "GABRIEL")
            else:
                w(output, t, "RICHARD")
            print "-----------------------"

def w(output, i, res):
    print result_string.format(i+1, res)
    output.write(result_string.format(i+1, res)+'\n')

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