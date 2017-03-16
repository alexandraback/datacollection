from itertools import *
from functools import *
from operator import *
from math import *
from collections import Counter
# from statistics import *

import os
import sys
sys.setrecursionlimit(10000)
os.chdir(os.path.dirname(os.path.realpath(__file__)))

filename = "A-large"
result_string = "Case #{}: {}"

numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
# numbers = [, "THREE", "FIVE", "EIGHT", ""]


specific_chars = {"Z": 0, "N": 1, "W": 2, "R":3, "U":4, "V":5, "X":6, "E":7, "G":8, "I":9}
order = [("Z", 0), ("W", 2), ("X", 6), ("S", 7), ("U", 4), ("O", 1), ("N", 9), ("F", 5), ("R", 3), ("E", 8)]

def main(input_filename, output_filename):
    with open(input_filename) as input, open(output_filename, 'w') as output:
        T, = nis(input)
        for t in range(T):
            c = Counter()
            S, = sis(input)
            s = Counter(S)
            phone_num = []
            for ch, n in order:
                count = s.get(ch)
                if count is not None:
                    if ch == "N":
                        count /= 2
                    for r in numbers[n]:
                        s[r] = s[r] - count
                        if ch =="N" and r == "N":
                            s[r] = s[r] - count
                    # print s
                    phone_num += [n] * count

            # print phone_num
            phone_num = sorted(phone_num)
            # print phone_num
            res = "".join(map(str, phone_num))
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
