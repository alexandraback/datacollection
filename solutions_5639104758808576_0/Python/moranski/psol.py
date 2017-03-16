#!/usr/bin/env python
import sys
import time
import cPickle
import re
import math
import itertools
import numpy as np
import networkx as nx


def DBG(*args, **kw):
    print >> sys.stderr, '  ->' * (kw.get('level',1)), 
    for a in args: print >> sys.stderr, a,
    print >> sys.stderr

class Case:
    def __init__(self, **ctx):
        self.__dict__.update( ctx )
        self.__ctx_names = ctx.keys()
        #self.pc = PreCalc(ctx) # precalc data
    
    def solve(self):
        DBG("in solve ", ' '.join( (( '%s=%s' % ( k, self.__dict__[k] ) for k in self.__ctx_names )) ) )
        M, A = self.M, self.A # A[i] = number of ppl with shyness i
        assert len(A) == M + 1
        standing = 0
        added = 0
        for i, n in enumerate(A):
            while standing < i:
                added += 1
                standing += 1
            standing += n

        return added

class ParsingMixIn:
    def ParseCase(self):
        M, A = self.NextTuple((long,str))
        A = map(int,A) 
        return Case(M = M, A = A)

    def NextLine(self):
        return self.IN.readline().strip()

    def NextTuple(self, tp):
        ret0 = re.split(r'\s+',self.NextLine())
        assert len(ret0) == len(tp)
        return tuple( (( f(i) for f,i in itertools.izip(tp, ret0) )) )

class WritingMixIn:
    def Write(self,case,sol):
        outstr =  "Case #%d: %s" % (case, sol)
        if self.OUTFN: DBG(outstr)
        print >> self.OUT, outstr

class Boiler(ParsingMixIn,WritingMixIn):
    def main(self):
        IN = INFN = None
        OUT = OUTFN = None
        if len(sys.argv)>1:
            INFN = sys.argv.pop()
            IN = open(INFN,'rt')
            OUTFN = INFN.rstrip('.in')+'.'+time.strftime('%Y-%m-%d_%H-%M-%S')+'.out'
            OUT = open(OUTFN,'wt')
        else:
            IN = sys.stdin
            OUT = sys.stdout

        self.IN, self.INFN = IN, INFN
        self.OUT, self.OUTFN = OUT, OUTFN
        self.loop()

    def loop(self):
        NCASE = long(self.IN.readline())
        for cas in range(NCASE):
            case = self.ParseCase()
            sol = case.solve()
            self.Write(cas+1,sol)

if __name__ == '__main__':
    Boiler().main()
