#!/usr/bin/python

from __future__ import division

import sys, os, subprocess
from pprint import pprint

def line():
    return FD.readline().strip()

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
dxy = zip(dx, dy)

NOMS = {1: [['x']]}
def getallnom(x):
    if x in NOMS:
        return NOMS[x]

    prev = NOMS[x-1]
    res = {}
    for p in prev:
        p = border(p)
        h = len(p)
        w = width(p)
        for i in range(h):
            for j in range(w):
                #print 'Try add at %d,%d' % (i,j)
                if p[i][j] == 'x': continue
                for dx, dy in dxy:
                    nx, ny = i+dx, j+dy
                    if 0 <= nx < h and 0 <= ny < w:
                        if p[nx][ny] == 'x':
                            break # ok
                else:
                    continue # niet goed

                np = trim(repl(p, i, j))
                first = getfamily(np)[0]
                res[signature(first)] = first

    NOMS[x] = res.values()
    return NOMS[x]

def signature(nom):
    return ','.join(nom)

def getfamily(nom):
    def rotright(nom):
        return [''.join(nom[len(nom)-1-j][i] for j in range(len(nom))) for i in range(width(nom))]
    def rev(nom):
        return list(reversed(nom))

    fam = [nom]
    for i in range(3):
        nom = rotright(nom)
        fam.append(nom)

    for nom in fam[:]:
        fam.append(rev(nom))

    famd = dict((signature(nom), nom) for nom in fam)
    fam = [v for k, v in sorted(famd.items())]

    return fam

def border(nom):
    w = width(nom)
    return [' '*(w+2)] + [' '+r+' ' for r in nom] + [' '*(w+2)]

def repl(nom, i, j):
    res = []
    for n, line in enumerate(nom):
        if n != i:
            res.append(line)
        else:
            res.append(line[:j] + 'x' + line[j+1:])
    return res

def trim(nom):
    nom = [line for line in nom if 'x' in line]
    if not any(line.startswith('x') for line in nom):
        nom = [line[1:] for line in nom]
    if not any(line.endswith('x') for line in nom):
        nom = [line[:-1] for line in nom]
    return nom

def width(nom):
    return len(nom[0])

def pr(nom):
    print '+' + '-' * width(nom)  + '+'
    for line in nom:
        print '|' + line + '|'
    print '+' + '-' * width(nom)  + '+'

def listall():
    for x in range(1, 8):
        noms = getallnom(x)
        print "%d-nominos (n=%d):" % (x, len(noms))
        #map(pr, noms)

def doit():
    N = int(line())
    for i in range(N):
        print 'Case #%d: %s' % (i+1, go())

def go():
    X,R,C = map(int, line().split())
    if X >= 7:
        return 'RICHARD' # Pick one with a hole
    if (R*C) % X != 0:
        return 'RICHARD'
    print >>sys.stderr, "Thinking about %d-nom in %dx%d" % (X, R, C),

    withfam = []
    for nom in getallnom(X):
        withfam += getfamily(nom)

    for nom in getallnom(X):
        # No need to get the whole family involved, except one rotation
        if solvable(R, C, nom, withfam):
            continue
        if solvable(C, R, nom, withfam):
            continue
        print >>sys.stderr, "RICHARD"
        return 'RICHARD'
    print >>sys.stderr, "GABRIEL"
    return 'GABRIEL'

class Grid(object):
    def __init__(self, R, C, noms):
        self.R = R
        self.C = C
        self.N = R*C
        self.grid = [[0]*C for i in range(R)]
        self.noms = noms

    def add(self, i, j, nom):
        jj = width(nom)
        ii = len(nom)

        if j + jj > self.C: return False
        if i + ii > self.R: return False

        wrongs = 0
        for di in range(ii):
            for dj in range(jj):
                self.grid[i+di][j+dj] += nom[di][dj] == 'x'
                wrongs += self.grid[di][dj] > 1
        if wrongs:
            self.rem(i, j, nom)
            return False
        return True

    def rem(self, i, j, nom):
        jj = width(nom)
        ii = len(nom)
        for di in range(ii):
            for dj in range(jj):
                self.grid[i+di][j+dj] -= nom[di][dj] == 'x'

def solvable(R, C, chosenone, noms):
    grid = Grid(R,C,noms)
    for i in range(grid.R):
        for j in range(grid.C):
            if grid.add(i, j, chosenone):
                if recur(grid, 0):
                    return True
                grid.rem(i, j, chosenone)
    return False

def recur(grid, s):
    if s == grid.N: return True

    j = s  % grid.C
    i = s // grid.C

    if grid.grid[i][j]:
        if recur(grid, s+1): return True
    for n in grid.noms:
        if grid.add(i, j, n):
            if grid.grid[i][j]:
                if recur(grid, s+1): return True
            grid.rem(i, j, n)

    return False

def main():
    listall()

    files = []
    for fn in os.listdir('.'):
        if fn.endswith('.in'):
            files.append((os.path.getmtime(fn), fn))
    fn = max(files)[1]


    root = fn[:-2]
    with open(fn) as fd:
        global FD
        FD = fd
        backupstdout = sys.stdout
        sys.stdout = open(root+'out', 'wb')
        doit()
        sys.stdout = backupstdout
        subprocess.call(['diff', '-sdu', root+'good', root+'out'])

if __name__ == '__main__':
    main()
