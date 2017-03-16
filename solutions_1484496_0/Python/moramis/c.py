#! /usr/bin/python

import sys, itertools

def getline():
    return sys.stdin.readline().strip()

DEBUG = False
def out(s):
    if DEBUG:
        sys.stderr.write(str(s) + '\n')

def all_combos(s):
    for x in range(1, len(s)):
        for y in itertools.combinations(s, x):
            yield y

class Case:
    def __init__(self, casenum):
        self.casenum = casenum
        self.map = {}

    def done(self, a, b):
        print 'Case #%d:' % (self.casenum,)
        if a and b:
            print ' '.join((str(x) for x in a))
            print ' '.join((str(x) for x in b))
        else:
            print 'Impossible'

    def solve(self):
        nums = [int(x.strip()) for x in getline().split()]
        count = nums[0]
        nums = nums[1:]
        for x in all_combos(nums):
            s = sum(x)
            if s in self.map:
                return self.done(x, self.map[s])
            else:
                self.map[s] = x
        return self.done(None, None)

cases = int(getline())
for case in xrange(cases):
    c = Case(case + 1)
    c.solve()
    del c
