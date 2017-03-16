#!/usr/bin/python2
### Google Code Jam template
# Futures
from __future__ import division
from __future__ import with_statement
from __future__ import print_function


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

## Problem

# Problem imports

# Helpers

def max_cells_covered(stones, W, H):
    assert W >= H
    if stones == 1:
        return 1
    if min(W, H) == 1:
        return stones
    # Assume we have no walls...
    length = stones // 2 + 1
    half_width = (length - 1) // 2
    width = 2 * half_width + 1
    extra_cell = stones % 2
    # ...but there are walls
    area = 0
    lines = [length - 2 * ((i + 1) // 2) for i in range(width)]
    for i in range(H):
        if i >= len(lines):
            break
        area += min(W, lines[i])
    if extra_cell:
        area += 1
    return area

# Working class
class Solver(ProblemSolver):
    def precalculate(self):
        ## User code here
        pass

    def process(self, infile, ncase):
        ## User code here
        N, M, K = readints(infile)
        if N < M:
            N, M = M, N
        for stones in range(K + 1):
            if max_cells_covered(stones, N, M) >= K:
                return stones
        raise Exception("Bad state!")

### Script code
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
