#!/usr/bin/python
# coding=utf8
import sys
import math
from time import time
from itertools import permutations, combinations
import collections
import functools
from fractions import gcd, Fraction
import string
import operator
#import random (not working in python3)
import bisect
from numpy import cross, dot, multiply, add, subtract
from numpy.linalg import norm

print_realtime = len(sys.argv) == 2 and sys.argv[1] == "print_realtime"

def dbg(txt):
    sys.stderr.write(str(txt) + "\n")


def print_var(*args):
    for var_name in args:
        assert type(var_name) == str
        calling_frame = sys._getframe().f_back
        var_val = calling_frame.f_locals.get(var_name, calling_frame.f_globals.get(var_name, None))
        dbg(var_name+'='+ str(var_val))


class timed(object):
    def __init__(self, func):
        self.func = func
    def __call__(self, *args):
        t1 = time()
        ret = self.func(*args)
        dif_time = time() - t1
        print("%s: returned %s in %f seconds" % (self.func.__name__, ret, dif_time))
        return ret


def comp(f1, f2, *args):
    t1 = time()
    r1 = f1(*args) if f1 is not None else None
    t2 = time()
    r2 = f2(*args) if f2 is not None else None
    t3 = time()
    res = "%5s: %s in %f\n%5s: %s in %f" % (f1.__name__ if f1 is not None else None, r1, t2 - t1,
                                            f2.__name__ if f2 is not None else None, r2, t3 - t2)
    if r1 != r2:
        dr = "!! DIFFERENT RESULTS !!"
        res = dr + "\n" + res + "\n" + dr
    print(res)
    return r1 if r1 == r2 else None


def alg(R, C, W):
    # count score for rows where the ship isn't (all but one)
    hits_in_wrong_rows = C // W
    # the first correct hit will be at idx C - W.
    # the ship is either toward one side or the other, we need to try both
    # hits are (W - 1) (remaining to hit)
    # + cases on the right side of hte first hit
    # dans tous les cas, on essaye d'abord un cpite, puis l'autre, donc il peut nous attraper que d'une case

    cells_before_first_hit = C - (hits_in_wrong_rows - 1) * W
    hits_before_first_hit = hits_in_wrong_rows - 1
    hits_including_first_hit = W + 1 if cells_before_first_hit > W else W
    hits_in_correct_row = hits_including_first_hit + hits_before_first_hit

    return hits_in_wrong_rows * (R - 1) + hits_in_correct_row


def main():
    #import cProfile
    #cProfile.runctx('alg()', globals(), locals())
    data = sys.stdin
    #data = open("in")
    nb = int(data.readline())
    #a, b = map(int,data.readline().split())
    for icase in range(nb):
        R, C, W = list(map(int, data.readline().split()))  # int
        #L = list(map(float, data.readline().split()))  # float
        #L = data.readline().split()  # string
        #s = data.readline().strip()
        #i = int(data.readline().strip())
        res = alg(R, C, W)
        ret = "Case #%d: %s" %(icase + 1, res)
        if print_realtime:
            dbg(ret)
        print(ret)


if __name__ == "__main__":
    main()
