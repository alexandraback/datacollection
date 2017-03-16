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


# Working class
class Solver(ProblemSolver):
    def precalculate(self):
        ## User code here
        pass

    def output(self, cells):
        if not cells:
            return '\nImpossible'
        if self.transpose:
            cells = [''.join(chars) for chars in zip(*cells)]
        answer = '\n' + '\n'.join(cells)
        try:
            assert answer.count('c') == 1
            assert answer.count('*') == self.M
            assert answer.count('.') == self.R * self.C - self.M - 1
            assert answer.count('\n') == self.R
            assert len(answer) == self.R * (self.C + 1)
        except AssertionError:
            import traceback
            traceback.print_exc()
        return answer

    def process(self, infile, ncase):
        ## User code here
        R, C, M = readints(infile)
        self.R, self.C, self.M = R, C, M
        free = R * C - M
        self.transpose = R > C
        if self.transpose:
            R, C = C, R
        # Special case: 1-D field
        if R == 1:
            cells = ['c' + '.' * (free - 1) + '*' * M]
            return self.output(cells)
        # Special case: single free cell
        if free == 1:
            cells = ['c' + '*' * (C - 1)] + ['*' * C] * (R - 1)
            return self.output(cells)
        # Common case: 3+ rows, 3+ cols
        for rows in range(2, R + 1):
            for cols in range(2, C + 1):
                max_free = rows * cols
                min_free = max_free - (rows - 2) * (cols - 2)
                if not min_free <= free <= max_free:
                    continue
                cells = []
                cells.append('c' + '.' * (cols - 1) +
                             '*' * (C - cols))
                cells.append('.' * cols +
                             '*' * (C - cols))
                extra_free = free - min_free
                active_cols = (cols - 2) if cols > 2 else 1
                full_rows = extra_free // active_cols
                mid_free = extra_free % active_cols
                for i in range(full_rows):
                    cells.append('.' * cols +
                                 '*' * (C - cols))
                if mid_free:
                    cells.append('.' * (2 + mid_free) +
                                 '*' * (C - (2 + mid_free)))
                for i in range(rows - full_rows - 2 - (1 if mid_free else 0)):
                    cells.append('.' * 2 +
                                 '*' * (C - 2))
                for i in range(R - rows):
                    cells.append('*' * C)
                return self.output(cells)
        print("Nothing found for {}, {}, {} -> {}".format(R, C, M, free))
        return self.output(None)

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
