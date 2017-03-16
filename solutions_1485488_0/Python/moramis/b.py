#! /usr/bin/python

import sys, itertools

rate = 10.0

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
        self.h, self.n, self.m = [int(x.strip()) for x in getline().split()]
        self.heightmap = []
        for _n in range(self.n):
            self.heightmap.append([int(x.strip()) for x in getline().split()])
        self.floormap = []
        for _n in range(self.n):
            self.floormap.append([int(x.strip()) for x in getline().split()])

        self.best = None
        return self.done(self.s(0.0, 0, 0, {}))

    def waterlevel(self, t):
        return self.h - t * rate

    def atExit(self, x, y):
        return x == self.m - 1 and y == self.n - 1

    def canGo(self, sx, sy, dx, dy, seen):
        return (0 <= dx < self.m
                and 0 <= dy < self.n
                and self.floormap[dy][dx] <= self.heightmap[dy][dx] - 50
                and self.floormap[sy][sx] <= self.heightmap[dy][dx] - 50
                and self.floormap[dy][dx] <= self.heightmap[sy][sx] - 50
                and not seen.get((dx, dy))
                )

    def go(self, t, sx, sy, dx, dy, seen):
        wl = self.waterlevel(t)
        if self.heightmap[dy][dx] - 50 < wl:
            wait = (wl - (self.heightmap[dy][dx] - 50)) / rate
            out('Waiting %f' % wait)
            t += wait
            wl = self.waterlevel(t)
        if t == 0.0:
            pass
        elif wl - self.floormap[sy][sx] >= 20.0:
            t += 1.0
        else:
            t += 10.0
        if not self.best is None and self.best <= t:
            return None
        return self.s(t, dx, dy, seen)

    def s(self, t, x, y, seen):
        out('Starting at (%s,%s) at %f having seen %s' % (x, y, t, str(seen)))
        seen = seen.copy()
        seen[(x, y)] = 1
        if self.atExit(x, y):
            self.best = t
            return t
        n, e, w, s = (None, None, None, None)
        if self.canGo(x, y, x, y - 1, seen):
            out('Trying north from (%s, %s) to (%s, %s)' % (x, y, x, y - 1))
            n = self.go(t, x, y, x, y - 1, seen)
        if self.canGo(x, y, x + 1, y, seen):
            out('Trying east from (%s, %s) to (%s, %s)' % (x, y, x + 1, y))
            e = self.go(t, x, y, x + 1, y, seen)
        if self.canGo(x, y, x - 1, y, seen):
            out('Trying west from (%s, %s) to (%s, %s)' % (x, y, x - 1, y))
            w = self.go(t, x, y, x - 1, y, seen)
        if self.canGo(x, y, x, y + 1, seen):
            out('Trying south from (%s, %s) to (%s, %s)' % (x, y, x, y + 1))
            s = self.go(t, x, y, x, y + 1, seen)

        options = filter(lambda z: not z is None, [n, e, w, s])
        if options:
            return min(options)
        else:
            return None

cases = int(getline())
for case in xrange(cases):
    Case(case + 1).solve()
