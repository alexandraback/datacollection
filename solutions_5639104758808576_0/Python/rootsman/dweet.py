#!/usr/bin/python
from operator import attrgetter
from operator import itemgetter

import sys

class tc:

  def __init__(self,tcIndex,instr):
    self.myIndex = tcIndex
    (self.sMax,self.inits) = theLine = instr.readline().split()
    self.maxNumPeeps = 0

  def solve(self):
    curS = 0
    borrowedPeople = 0
    peopleUp = 0
    for c in self.inits:
      peopleThisS = int(c)
      while ( curS > peopleUp ):
        borrowedPeople += 1
        peopleUp += 1
      peopleUp += peopleThisS
      curS += 1
    self.maxNumPeeps = borrowedPeople

  def share(self,ostr):
    ostr.write ( 'Case #%i: %i\n' % (self.myIndex,self.maxNumPeeps) )

def main():
  numTC = int(sys.stdin.readline().strip())
  for tci in range(0,numTC):
    theTC = tc(tci+1,sys.stdin)
    theTC.solve()
    theTC.share(sys.stdout)


main()
