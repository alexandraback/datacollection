## CodeJam 2014
## Author: Jon Eisen
## Round: Qualifier
## Problem: C - Minesweeper Master

# Run With
# python file.py file.in

# This is from the pycodejam open source package by Jon Eisen (yours truly)
from codejam import CodeJam, parsers
from itertools import *

IMPOSSIBLE = '\nImpossible'
EMPTY = '.'
MINE = '*'
CLICK = 'c'

@parsers.iter_parser
def parse(next):
  r, c, m = map(int, next().split(' '))
  return r, c, m

def solve(r, c, m):
  return Grid(r,c,m).run()

class Grid:
  def __init__(self, r, c, m, g=None, edges=None, empty=None):
    self.g = g or [[MINE for i in range(c)] for j in range(r)]
    self.edges = edges or [(j,i) for i in range((c+1)/2) for j in range((r+1)/2)]
    self.r = r
    self.c = c
    self.m = m
    self.total = r*c
    self.empty = empty or (self.total - m)
  def validate(self):
    mines = sum(sum(s == MINE for s in row) for row in self.g)
    assert self.m == mines
  def __str__(self):
    out = '\n'
    for row in self.g:
      out += ''.join(row) + '\n'
    return out[:-1]
  def setZero(self, en):
    x, y = en
    if self.g[x][y] == MINE:
      self.g[x][y] = 'c'
      self.empty -= 1
      self.edges = []
    for zx, zy in self.around(x,y):
      if self.g[zx][zy] == MINE:
        self.g[zx][zy] = '.'
        self.empty -= 1
        self.addEdge(zx, zy)

  def copy(self):
    return Grid(self.r,self.c,self.m,[[i for i in row] for row in self.g],[e for e in self.edges], self.empty)

  def setZeroCopy(self, en):
    cp = self.copy()
    cp.setZero(en)
    return cp

  def around(self, x, y):
    return [(zx, zy) for zx in (x-1,x,x+1) for zy in (y-1,y,y+1) if zy >= 0 if zx >= 0 if zx < self.r if zy < self.c]
  def potential(self, x,y):
    return sum(1 for (zx,zy) in self.around(x,y) if self.g[zx][zy] == MINE)
  def addEdge(self, x,y):
    self.edges.append((x,y))
  def getPotentials(self):
    pots = []
    edges = []
    for edge in self.edges:
      pot = self.potential(*edge)
      if pot > 0:
        edges.append(edge)
        pots.append((pot, edge))
    self.edges = edges
    return pots

  def run(self):
    if self.m == self.total:
      return IMPOSSIBLE
    elif self.r == 1:
      self.g[0][0] = CLICK
      for i in range(1,self.empty):
        self.g[0][i] = EMPTY
      return self
    elif self.c == 1:
      self.g[0][0] = CLICK
      for i in range(1,self.empty):
        self.g[i][0] = EMPTY
      return self
    elif self.m == 0:
      self.g = [[EMPTY for i in range(self.c)] for j in range(self.r)]
      self.g[0][0] = CLICK
      return self
    elif self.empty == 1:
      self.g[0][0] = CLICK
      return self

    res = self.master()
    if res != IMPOSSIBLE:
      res.validate()
    return res

  def master(self):

    ## special cases
    if self.empty == 0:
      return self

    pots = self.getPotentials()
    poss = list(reversed(sorted((pot, pos) for pot,pos in pots if pot <= self.empty)))
    # print (self.r, self.c), self.empty, poss, self
    if len(poss) == 0:
      return IMPOSSIBLE

    for _, pos in poss:
      trial = self.setZeroCopy(pos).master()
      if trial != IMPOSSIBLE:
        return trial

    return IMPOSSIBLE


if __name__ == "__main__":
  CodeJam(parse, solve).main()
