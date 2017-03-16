#!/usr/bin/python
from operator import attrgetter
from operator import itemgetter

import sys

qmt = { ('1','1') : ('1',+1) \
      , ('1','i') : ('i',+1) \
      , ('1','j') : ('j',+1) \
      , ('1','k') : ('k',+1) \

      , ('i','1') : ('i',+1) \
      , ('i','i') : ('1',-1) \
      , ('i','j') : ('k',+1) \
      , ('i','k') : ('j',-1) \

      , ('j','1') : ('j',+1) \
      , ('j','i') : ('k',-1) \
      , ('j','j') : ('1',-1) \
      , ('j','k') : ('i',+1) \

      , ('k','1') : ('k',+1) \
      , ('k','i') : ('j',+1) \
      , ('k','j') : ('i',-1) \
      , ('k','k') : ('1',-1) \
      }

def qm(a,b):
    prodTup = qmt[(a[0],b[0])]
    return (prodTup[0],prodTup[1]*a[1]*b[1])

class tc:

  def __init__(self,tcIndex,instr):
    self.myIndex = tcIndex
    (self.strLen,self.strRep) = instr.readline().split()
    self.strLen = int(self.strLen)
    self.strRep = int(self.strRep)
    self.theStr = instr.readline().strip().lower()
    self.doYouEvenIjk = False

  def solve(self):

    # first figure out what the string evals to
    curAns = ('1',+1)
    for x in self.theStr:
      curAns = qm(curAns,(x,+1))
    strVal = curAns

    # print 'TheStr evals to %i*%s' % (strVal[1],strVal[0])
    # need strVal ^ strRep to be -1 (=== i*j*k) or no-go-even-in-slo-mo
    effRep = None
    if ( strVal == ('1',-1) ): # works only with odd powers
      if ( self.strRep % 2 == 1 ):
        effRep = min(21,self.strRep)
    elif ( strVal == ('1',+1) ): # will never reach +1 total
      pass
    elif ( self.strRep % 4 == 2 ): # covers cases where strVal is +/- i/j/k
      effRep = min(12,self.strRep)

    if ( effRep is None ):
      self.doYouEvenIjk = False
      return

    nrAtI = False
    nrAtIJ = False

    curAns = ('1',+1)
    # sys.stdout.write('\n')
    for cr in range(0,effRep):
      for x in self.theStr:
        curAns = qm(curAns,(x,+1))
        # if ( curAns[1] == -1 ): sys.stdout.write('-')
        # else                  : sys.stdout.write('+')
        # sys.stdout.write('%s ' % curAns[0])
        if ( not nrAtI ):
          if ( curAns == ('i',+1) ):
            nrAtI = True
            # sys.stdout.write('{I}')
        elif ( not nrAtIJ ):
          if ( curAns == ('k',+1) ):
            nrAtIJ = True
           #  sys.stdout.write('{K}')
    # sys.stdout.write('\n\n')
    self.doYouEvenIjk = nrAtI and nrAtIJ


  def solve_gumpy(self):

    nrAtI = False
    nrAtIJ = False

    curAns = ('1',+1)
    for cr in range(0,self.strRep):
      for x in self.theStr:
        curAns = qm(curAns,(x,+1))
        if ( not nrAtI ):
          if ( curAns == ('i',+1) ):
            nrAtI = True
        elif ( not nrAtIJ ):
          if ( curAns == ('k',+1) ):
            nrAtIJ = True
    self.doYouEvenIjk = nrAtI and nrAtIJ and (curAns == ('1',-1))

  def share(self,ostr):
    ostr.write ( 'Case #%i: ' % self.myIndex )
    if ( self.doYouEvenIjk ): ostr.write ( 'YES\n' )
    else                    : ostr.write ( 'NO\n' )

def main():
  numTC = int(sys.stdin.readline().strip())
  for tci in range(0,numTC):
    theTC = tc(tci+1,sys.stdin)
    theTC.solve()
    theTC.share(sys.stdout)


main()
