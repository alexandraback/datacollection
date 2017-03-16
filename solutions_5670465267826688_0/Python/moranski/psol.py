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

qord = 'ijk'
def qinvert(q):
    if len(q) == 1:
        return '-'+q
    return q[1]

def qmult(q1,q2):
    minus = False
    if len(q1) == 2: 
        q1, minus = q1[1], not minus
    if len(q2) == 2: 
        q2, minus = q2[1], not minus
    
    if minus:
        return qinvert(qmult(q1,q2))
    
    if q1 == '1': return q2
    if q2 == '1': return q1
    if q1 == q2: 
        return '-1'
    return {'ij':'k','jk':'i','ki':'j',
            'ji':'-k','kj':'-i','ik':'-j'}[q1+q2]

class Case:
    def __init__(self, **ctx):
        self.__dict__.update( ctx )
        self.__ctx_names = ctx.keys()
        #self.pc = PreCalc(ctx) # precalc data
    
    def solve(self):
        DBG("in solve ", ' '.join( (( '%s=%s' % ( k, self.__dict__[k] ) for k in self.__ctx_names )) ) )
        
        #to reduce to ijk - need to have two conditions:
        # 1. product = -1. - easy
        # 2. can produce j in the middle. j is not a power of any unit quaternion except j or -j.
        #   case 2a - j is literally in the given string - if X = 1.
        if not self.prod_is_minus1(): 
            #DBG("prod is not minus1")
            return "NO"
        if not self.can_make_ijk(): 
            #DBG("cannot make ijk")
            return "NO"
        return "YES"
    
    def prod_is_minus1(self):
        Sval = '1'
        Sval = reduce(qmult, self.S, Sval)
        allval = reduce(qmult, [ Sval ] * (self.X % 4), '1')
        return allval == '-1'
    
    def can_make_ijk(self):
        L, X, S = self.L, self.X, self.S
        iprod = '1'
        irange = min(L*4, L * X - 2) 
        # no need to look beyond L*4 and can't look beyond L*X - 2 since these are j and k...
        for i in xrange(irange):
            iprod = qmult(iprod, self.S[i % L])
            if iprod == 'i':
                jrange = min(i + 1 + L*4, L * X - 1)
                jprod = '1'
                for j in xrange(i+1, jrange):
                    jprod = qmult(jprod,S[j % L])
                    if jprod == 'j':
                        return True
        return False


class ParsingMixIn:
    def ParseCase(self):
        casedict = dict(zip("LX", self.NextTuple((long,long))))
        casedict['S'] = self.NextLine()
        assert len(casedict['S']) == casedict['L']
        return Case(**casedict)

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
