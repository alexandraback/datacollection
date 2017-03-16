#!/usr/bin/env python3

from functools import reduce
from operator import mul
import sys

def strategy_1(probs, a, b):
    p_c = reduce(mul, probs)
    return p_c * ((b - a) + 1) + (1 - p_c)*(b + 1 + (b - a) + 1)

def strategy_3(b):
    return b + 2

def strategy_2(probs, bspaces, a, b):
    p_cn = reduce(mul, probs[:(a-bspaces)])
    try_1 = 2 * bspaces + (b - a) + 1
    return p_cn * try_1 + (1 - p_cn) * (try_1 + b + 1)

if __name__ == "__main__":
    with open(sys.argv[1]) as f, open(sys.argv[2], "w") as out:
        count = int(f.readline())
        for i in range(1, count + 1):
            a, b = [int(j) for j in f.readline().strip().split()]
            probs = [float(j) for j in f.readline().strip().split()]
            out.write("Case #%d: %f\n" % (i, min([strategy_1(probs, a, b), strategy_3(b)] + [strategy_2(probs, j, a, b) for j in range(1, a)])))
