#from __future__ import division

from Tools import gcj
#from __future__ import division
#from functools32.functools32 import lru_cache
import sys
import itertools
import os
import re
import string
import math
import sys
import heapq
from collections import namedtuple, defaultdict, deque
from Tools.gcj import printd
from copy import deepcopy
#from simpleai.search import SearchProblem, astar
import random
import operator
#from Tools import primes
#from itertools import product


def count_pairs(i, j, previous, option):
    a = option[i]
    b = option[j]
    c = 0
    for p in previous:
        if p[i] == a and p[j] == b:
            c += 1
    return c

def is_compatible(previous, option, k):
    if option in previous:
        return False

    if count_pairs(0, 1, previous, option) == k:
        return False
    if count_pairs(0, 2, previous, option) == k:
        return False

    if count_pairs(1, 2, previous, option) == k:
        return False
    return True

def res(solution):
    s = str(len(solution))
    for line in solution:

        s += "\n"
        s += str(line[0]) + " " + str(line[1]) + " " + str(line[2])
    return s


def solverec(previous, totals, k):
    global maxiter
    maxiter -= 1
    if (maxiter % 100000 == 0):
        print maxiter
    if (maxiter <= 0):
        return previous
    #need to change 2 things!
    best_option = previous
    #print previous
    #print len(previous)
    for a in xrange(1, totals[0] + 1):
      for b in xrange(1, totals[1] + 1):
        for c in xrange(1, totals[2] + 1):
              option = (a,b,c)
              if is_compatible(previous,option, k):
                new_previous = set(previous)
                new_previous.add(option)

                x = solverec(new_previous, totals, k)
                if len(x) > len(best_option):
                    best_option = x
    return best_option


def solver(j,p,s,k):
    global maxiter
    maxiter = 1000000
    printd(j,p,s,k)

    # poss = []
    # for a in xrange(1, j + 1):
    #     for b in xrange(1, p + 1):
    #         for c in xrange(1, s + 1):
    #             for d in xrange(1 , k+ 1):
    #                 poss.append((a,b,c,d))
    previous = set()
    previous.add((1,1,1))
    if (j > 1 and p > 1 and s > 1):
        previous.add((2,2,2))
    if (j > 2 and p > 2 and s > 2):
        previous.add((3,3,3))

    s = solverec(previous, (j, p, s), k)
    return res(s)

def reader(in_file):
    """
    @type in_file: gcj.FileWrapper
    """
    (j,p,s,k) = in_file.getInts()

    return {
        'j': j,
        'p': p,
        's': s,
        'k': k
    }


if __name__ == "__main__":
    ### GCJ module http://jamftw.blogspot.com.es/2012/05/python-code-jam-wrapper.html
    gcj.GCJ(reader, solver, os.getcwd(), "").run()
