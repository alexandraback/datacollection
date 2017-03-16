#!/usr/bin/pypy

import sys
import select

TEST = not select.select([sys.stdin,],[],[],0.0)[0]
DEBUG = False


sample = """4
2 2
2 1
2 4
2 1 1 6
10 4
25 20 9 100
1 4
1 1 1 1
"""

def debug(s):
    if DEBUG:
        print s

def linegen():
    if TEST:
        for line in sample.splitlines():
            yield line
    else:
        yield sys.stdin.readline()
        for line in sys.stdin.readlines():
            debug(line)
            yield str(line[:-1])

lg = linegen()
def solve(A, motes):
    motes = sorted(motes)
    return minscore(0, A, motes)

def minscore(pos, A, motes):
    debug("Testing motes %s " % motes)
    if A == 1: return len(motes)

    while pos < len(motes) and A > motes[pos]:
        A += motes[pos]
        pos += 1

    # the problem is already solvable
    if pos == len(motes):
        return 0

    # Recurse on adding a mote and subtracting a mode, and return the minimum option
    addscore = 1 + minscore(0, A, [A - 1] + motes[pos:])
    subscore = 1 + minscore(0, A, motes[pos+1:])
    return min(addscore, subscore)


T = int(lg.next())
for i in range(1,T+1):
    A, N = [int(s) for s in lg.next().split()]
    print "Case #%d: %s" % (i, solve(A, [int(s) for s in lg.next().split()]))

