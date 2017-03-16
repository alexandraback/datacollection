#!/usr/bin/python
from operator import attrgetter
from operator import itemgetter

import sys

class tc:

  def __init__(self,tcIndex,instr):
    self.myIndex = tcIndex
    self.D = int(instr.readline())
    self.Pis = [int(f) for f in instr.readline().split()]
    self.minMins = None

  def solve(self):
    # small: 1-6 diners with 1-9 panx each
    # large: 1-1000 diners with 1-1000 panx each
    self.minMins = max(self.Pis)
    for eatTarget in range(1,1+max(self.Pis)):
      magicCost = 0
      for Pi in self.Pis:
        cPi = Pi
        while ( cPi > eatTarget ):
          cPi -= eatTarget
          magicCost += 1
      #print "eatTarget %i: magicCost %i" % (eatTarget,magicCost)
      if (eatTarget + magicCost) < self.minMins:
        self.minMins = eatTarget + magicCost


  def share(self,ostr):
    ostr.write ( 'Case #%i: %i\n' % (self.myIndex,self.minMins) )

def main():
  numTC = int(sys.stdin.readline().strip())
  for tci in range(0,numTC):
    theTC = tc(tci+1,sys.stdin)
    theTC.solve()
    theTC.share(sys.stdout)


main()
