#! /usr/bin/python

import sys, itertools

def getline():
    return sys.stdin.readline().strip()

DEBUG = True
def out(s):
    if DEBUG:
        sys.stderr.write(str(s) + '\n')

class Level:
    def __init__(self, a, b):
        self.req1 = a
        self.req2 = b
        self.record = 0

class Case:
    def __init__(self, casenum):
        self.casenum = casenum

    def done(self, answer):
        print 'Case #%d: %s' % (self.casenum, answer)

    def solve(self):
        numLevels = int(getline())
        stars = 0
        games = 0
        levels = []
        for i in range(numLevels):
            a, b = [int(x) for x in getline().split()]
            levels.append(Level(a, b))

        while levels:
            foundSomething = False
            toRemove = []
            # complete as many 2-stars as we can
            for index, level in enumerate(levels):
                if level.req2 <= stars:
                    foundSomething = True
                    games += 1
                    stars += 2 - level.record
                    toRemove.append(index)

            if foundSomething:
                toRemove.reverse()
                for index in toRemove:
                    del levels[index]
                continue

            for index, level in enumerate(levels):
                if level.record == 0 and level.req1 <= stars:
                    foundSomething = True
                    games += 1
                    stars += 1
                    level.record = 1
                    break

            if not foundSomething:
                break

        if levels:
            answer = 'Too Bad'
        else:
            answer = games

        self.done(answer)

cases = int(getline())
for case in xrange(cases):
    Case(case + 1).solve()
