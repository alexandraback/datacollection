#!/usr/bin/python2
### Google Code Jam template
# Futures
from __future__ import division
from __future__ import with_statement
from __future__ import print_function

from itertools import chain
from collections import Counter
from math import factorial

## Library
# @memoized
def memoized(func):
    mem = {}

    def wrapped(*args):
        if args not in mem:
            mem[args] = func(*args)
        return mem[args]
    return wrapped

## Input templates
# Line as int
readint = lambda infile: int(infile.readline())
# Line as many ints
readints = lambda infile: [int(s) for s in infile.readline().split()]


# Base class
class ProblemSolver(object):
    def __init__(self):
        self.precalculate()

    def precalculate(self):
        raise NotImplementedError

    def process(self, infile, ncase):
        raise NotImplementedError

    def run(self, infile, outfile):
        cases = int(infile.readline())
        for ncase in range(cases):
            print("Case #{nc}".format(nc=ncase + 1))
            # Perform all nessesary calculation
            data = self.process(infile, ncase=ncase)
            outfile.write("Case #{nc}: {data}\n".format(
                nc=ncase + 1, data=data))


class Train:
    def __init__(self, cars):
        self.cars = cars
        self.left = cars[0]
        current = self.left
        self.inner = []
        for car in cars:
            if car == current:
                continue
            self.inner.append(current)
            current = car
        self.right = current
        if self.inner:
            self.inner = self.inner[1:]
        if self.right == self.left and not self.inner:
            self.single = self.left
        else:
            self.single = None


# Working class
class Solver(ProblemSolver):
    def precalculate(self):
        ## User code here
        pass

    def process(self, infile, ncase):
        ## User code here
        infile.readline()
        trains = [Train(s) for s in infile.readline().split()]
        inners = Counter(chain(*[t.inner for t in trains]))
        if inners and max(inners.values()) > 1:
            return 0
        inners = set(inners.keys())
        train_count = len(trains)
        variant_count = 1
        free_ends = 0
        for letter in sorted(set(chain(*[t.cars for t in trains]))):
            single_count = len([t for t in trains if t.single == letter])
            left_count = len([t for t in trains if t.left == letter]) - single_count
            right_count = len([t for t in trains if t.right == letter]) - single_count
            if not max([single_count, left_count, right_count]):
                continue
            if letter in inners:
                return 0
            if left_count > 1 or right_count > 1:
                return 0
            variant_count *= factorial(single_count)
            variant_count %= 1000000007
            free_ends += (2 - left_count - right_count)
            train_count -= left_count + single_count + right_count - 1
        variant_count *= factorial(train_count)
        variant_count %= 1000000007
        if free_ends < 2:
            return 0
        return variant_count


# Script code
if __name__ == '__main__':
    ## Setup
    # Task letter
    from os.path import basename, splitext
    TASK = splitext(basename(__file__))[0]
    print("Task {}".format(TASK))
    from sys import argv
    if len(argv) > 1:
        print("Filename given: {}".format(argv[1]))
        FILE = splitext(argv[1])[0]
    else:
        FILE = TASK
    ## Precalculation
    print("Initialization...")
    solver = Solver()
    print("Initialization done.")
    ## Calculation
    print("Calculation...")
    with open(FILE + ".in") as infile:
        with open(FILE + ".out", mode="wt") as outfile:
            solver.run(infile, outfile)
    print("Calculation done.")
