from itertools import *
from functools import *
from operator import *
from math import *
from collections import Counter
from heapq import *

import os
os.chdir(os.path.dirname(os.path.realpath(__file__)))

filename = "B-small-attempt3"
result_string = "Case #{}: {}"


def do_split(heap):
    if not heap:
        return False
    if len(heap) < 2:
        nosplit = -heap[0]
        a = nosplit/2
        b = nosplit - a
        return max(a, b) + 1 < nosplit
    else:
        nosplit = -heap[0]

        a = nosplit/2
        b = nosplit - a
        c = -min(heap[1:])
        return max(a, b, c) + 1 < nosplit



def main(input_filename, output_filename):
    with open(input_filename) as input, open(output_filename, 'w') as output:
        T, = nis(input)
        for t in range(T):
            D, = nis(input)
            P = nis(input)
            P = map(lambda x: -x, P)
            heapify(P)
            # special_minutes = 0
            s = []
            for i in xrange(9):
                # print "wtf", P
                s.append(-P[0] + i)
                a = -heappop(P)
                heappush(P, -(a/2))
                heappush(P, -(a - a/2))
                # s.append(-P[0] + i + 1)
            # while do_split(P):
            #     special_minutes += 1
            #     a = heappop(P)
            #     heappush(P, a/2)
            #     heappush(P, a - a/2)
            #     print "splitting {} to {} and {}".format(a, a/2, a - a/2)
            # print s
            # print s
            # res = min(s)
            w(output, t, min(s))
            # print "--------------"

def w(output, i, res):
    print result_string.format(i+1, res)
    output.write(result_string.format(i+1, res)+'\n')

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