from itertools import *
from functools import *
from operator import *
from math import *
from collections import Counter

import os
os.chdir(os.path.dirname(os.path.realpath(__file__)))

filename = "C-large"
result_string = "Case #{}: {}"

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


def precheck((c, q), X):
    if (c, q) == (-1, 1) and X%2 == 1:
        return True
    if q != 1 and X%4 == 2:
        return True
    return False

def main(input_filename, output_filename):
    with open(input_filename) as input, open(output_filename, 'w') as output:
        T, = nis(input)
        for t in range(T):
            L, X = nis(input)
            Q, = sis(input)
            res = "NO"
            # preliminary exams:
            q = reduce(mult, trans(Q), (1, 1))
            if precheck(q, X):
                QQ = Q * 4

                found_i = False
                maybe_i = (1, 1)
                for i, qq in enumerate(QQ):
                    maybe_i = mult(maybe_i, (1, qq))
                    if maybe_i == (1, 'i'):
                        found_i = True
                        break
                
                found_k = False
                maybe_k = (1, 1)
                for k, qq in enumerate(reversed(QQ)):
                    maybe_k = mult((1, qq), maybe_k)
                    if maybe_k == (1, 'k'):
                        found_k = True
                        break
                
                if found_i and found_k:
                    k = len(Q) * X - k - 1
                    if (0 <= i < len(Q) * X) and (i + 1 < k < len(Q) * X):
                        res = "YES"
            w(output, t, res)





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