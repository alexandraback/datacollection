#! /usr/bin/python

import sys, itertools

def getline():
    return sys.stdin.readline().strip()

DEBUG = False
def out(s):
    if DEBUG:
        sys.stderr.write(str(s) + '\n')

class Case:
    def __init__(self, casenum):
        self.casenum = casenum

    def done(self, answer):
        print 'Case #%d: %s' % (self.casenum, answer)

    def solve(self):
        typedSoFar, length = [int(x) for x in getline().split()]
        ps = [float(x) for x in getline().split()]

        ifEnter = length + 2

        correctMatrix = [1.0]
        for p in ps:
            correctMatrix.append(p * correctMatrix[-1])

        ifBackspace = []
        for backspaces in range(typedSoFar + 1):
            correctKeys = length - typedSoFar + 1 + (2 * backspaces)
            incorrectKeys = length + length - typedSoFar + 2 + (2 * backspaces)
            correctChance = correctMatrix[-(backspaces + 1)]
            incorrectChance = 1.0 - correctChance
            ifBackspace.append(correctKeys * correctChance
                               + incorrectKeys * incorrectChance)
        self.done(min(ifEnter, min(ifBackspace)))

cases = int(getline())
for case in xrange(cases):
    Case(case + 1).solve()
