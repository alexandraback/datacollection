from itertools import *
from functools import *
from operator import *
from math import *
from collections import Counter

import os
os.chdir(os.path.dirname(os.path.realpath(__file__)))

filename = "C-small-attempt1"
result_string = "Case #{}: {}"

global i; i = 'i'
global j; j = 'j'
global k; k = 'k'

def mult((s1, q1), (s2, q2)):
    t = {
        1: {1: (1, 1), 'i': (1, 'i'), 'j': (1, 'j'), 'k': (1, 'k')},
        'i': {1: (1, 'i'), 'i': (-1, 1), 'j': (1, 'k'), 'k': (-1, 'j')},
        'j': {1: (1, 'j'), 'i': (-1, 'k'), 'j': (-1, 1), 'k': (1, 'i')},
        'k': {1: (1, 'k'), 'i': (1, 'j'), 'j': (-1, 'i'), 'k': (-1, 1)},
    }
    (s3, q3) = t[q1][q2]
    return (s1*s2*s3, q3)

def trans(l):
    return [(1, q) for q in l]

def main(input_filename, output_filename):
    with open(input_filename) as input, open(output_filename, 'w') as output:
        T, = nis(input)
        for t in range(T):
            L, X = nis(input)
            LL, = sis(input)
            # print L, len(l)
            assert len(LL) == L
            LL = LL * X
            q1 = (1, 1)
            q2 = reduce(mult, trans(LL), (1, 1))
            res = "NO"
            if q2 == (-1, 1):
                for e, q in enumerate(LL):
                    # print e
                    q1 = mult(q1, (1, q))
                    q2 = mult((-1, q), q2)
                    if q1 == (1, i):
                        q21 = (1, 1)
                        q22 = q2
                        for f, r in enumerate(LL[e+1:]):
                            q21 = mult(q21, (1, r))
                            q22 = mult((-1, r), q22)
                            if q21 == (1, j) and q22 == (1, k):
                                res = "YES"
                                break
                    if res == "YES":
                        break
            w(output, t, res)

            # for a in xrange(len(l) - 2):
            #     print a
            #     q1 = mult(q1, (1, l[a]))
            #     q2 = (1, l[a+1])
            #     q3 = reduce(mult, trans(l[a+2:]), (1, 1))
            #     # print q1, q2, q3
            #     for b in xrange(a+2, len(l)):
            #         if (q1 == (1, 'i')) and (q2 == (1, 'j')) and (q3 == (1, 'k')):
            #             res = "YES"
            #             break
            #         q2 = mult(q2, (1, l[b]))
            #         q3 = mult((-1, l[b]), q3)
            #         # q2 = reduce(mult, trans(l[a:b]), (1, 1))
            #         # q3 = reduce(mult, trans(l[b:]), (1, 1))
            print res
            print "----------------"
            # if t == 3:
            #     break






def w(output, i, res):
    print result_string.format(i+1, res)
    output.write(result_string.format(i+1, res)+'\n')

def sis(input):
    return input.readline().split()

def nis(input):
    return map(int, input.readline().split())

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