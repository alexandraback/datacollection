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
                    nc=ncase + 1,data=data))

# Working class
from collections import deque
from heapq import heappush, heappop
class Solver(ProblemSolver):
    def precalculate(self):
        ## User code here
        pass

    def process(self, infile, ncase):
        ## User code here
        H, N, M = readints(infile)
        C = [readints(infile) for i in range(N)]
        F = [readints(infile) for i in range(N)]
        self.ceil = {}
        self.floor = {}
        self.visited = {}
        for i in range(N):
            for j in range(M):
                self.ceil[i, j] = C[i][j]
                self.floor[i, j] = F[i][j]
                self.visited[i, j] = False
        places = [(0, (0, 0))]
        while len(places):
            time, s = heappop(places)
            # Already been here?
            if self.visited[s]:
                continue
            self.visited[s] = True
            # Are we done?
            if s == (N-1, M-1):
                return time
            # Where can we go?
            for d in ((s[0]-1,s[1]), (s[0]+1,s[1]),
                    (s[0],s[1]-1), (s[0],s[1]+1)):
                # Not outside the dungeon?
                if d[0] < 0 or d[0] >= N or d[1] < 0 or d[1] >= M:
                    continue
                # Can we move?
                wait, move = self.move_time(s, d, H - 10 * time, 10)
                if wait is None:
                    continue
                if time > 0 or wait > 0:
                    heappush(places, (time + wait + move, d))
                else:
                    heappush(places, (0, d))


    def move_time(self, src, dst, level, speed):
        if (self.ceil[dst] - self.floor[dst] < 50 or
                self.ceil[dst] - self.floor[src] < 50 or
                self.ceil[src] - self.floor[dst] < 50):
            return None, None
        wait = 0
        if self.ceil[dst] - level < 50:
            if not speed:
                return None, None
            else:
                wait = (50 - (self.ceil[dst] - level)) / speed
        return wait, (1 if ((level - speed * wait) - self.floor[src] >= 20)
                else 10)

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
    with open('/home/useruser/datacollection/input/1485488_0.in' ,'r') as infile:
        with open('/home/useruser/datacollection/input/1485488_0.in' ,'r') as outfile:
            solver.run(infile, outfile)
    print("Calculation done.")
