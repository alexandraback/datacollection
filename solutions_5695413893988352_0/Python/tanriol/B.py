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

    def process(self, infile, ncase):
        ## User code here
        templates = infile.readline().split()
        left, right = templates

        candidates = []
        left_prefix = ""
        right_prefix = ""
        for l, r in zip(*templates):
            if l == r:
                if l != '?':
                    left_prefix += l
                    right_prefix += r
                else:
                    candidates.append(
                        (left_prefix + '0' + left[len(left_prefix) + 1:].replace('?', '9'),
                         right_prefix + '1' + right[len(right_prefix) + 1:].replace('?', '0'))
                        )
                    candidates.append(
                        (left_prefix + '1' + left[len(left_prefix) + 1:].replace('?', '0'),
                         right_prefix + '0' + right[len(right_prefix) + 1:].replace('?', '9'))
                        )
                    left_prefix += '0'
                    right_prefix += '0'
            elif l == '?':
                if r != '0':
                    candidates.append(
                        (left_prefix + str(int(r) - 1) + left[len(left_prefix) + 1:].replace('?', '9'),
                        right_prefix + r + right[len(right_prefix) + 1:].replace('?', '0'))
                        )
                if r != '9':
                    candidates.append(
                        (left_prefix + str(int(r) + 1) + left[len(left_prefix) + 1:].replace('?', '0'),
                        right_prefix + r + right[len(right_prefix) + 1:].replace('?', '9'))
                        )
                left_prefix += r
                right_prefix += r
            elif r == '?':
                if l != '9':
                    candidates.append(
                        (left_prefix + l + left[len(left_prefix) + 1:].replace('?', '9'),
                        right_prefix + str(int(l) + 1) + right[len(right_prefix) + 1:].replace('?', '0'))
                        )
                if l != '0':
                    candidates.append(
                        (left_prefix + l + left[len(left_prefix) + 1:].replace('?', '0'),
                        right_prefix + str(int(l) - 1) + right[len(right_prefix) + 1:].replace('?', '9'))
                        )
                left_prefix += l
                right_prefix += l
            else:
                if int(l) < int(r):
                    candidates.append(
                        (left_prefix + l + left[len(left_prefix) + 1:].replace('?', '9'),
                         right_prefix + r + right[len(right_prefix) + 1:].replace('?', '0'))
                        )
                else:
                    candidates.append(
                        (left_prefix + l + left[len(left_prefix) + 1:].replace('?', '0'),
                         right_prefix + r + right[len(right_prefix) + 1:].replace('?', '9'))
                        )
                break
        else:
            candidates.append((left_prefix, right_prefix))
        print(candidates)
        answer = min(candidates, key=lambda (l, r): (abs(int(l) - int(r)), int(l), int(r)))
        return ' '.join(answer)




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
