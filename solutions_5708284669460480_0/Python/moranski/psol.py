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
        probs = {}
        for k in self.KBD:
            if k not in probs: probs[k] = 0L
            probs[k] += 1L
        for i in self.TARGET:
            if i not in probs: return 0.0
        DBG(probs)
        all_options = itertools.product(probs.keys() , repeat = self.S)
        match_cnt = 0
        max_matches = 0
        for p in all_options:
            matches = 0
            s = ''.join(p)
            i = 0
            while True:
                i = s.find(self.TARGET,i)
                if i == -1: break
                i = i + 1
                matches += 1
            max_matches = max(max_matches, matches)
            match_cnt = match_cnt + matches * reduce(long.__mul__, ((  probs[i] for i in p )),1L)

        return max_matches - ( match_cnt * 1.0 / (len(self.KBD) ** self.S))

class ParsingMixIn:
    def ParseCase(self):
        casedict = dict(zip("KLS", self.NextTuple((long,long,long))))
        casedict['KBD'] = self.NextLine()
        casedict['TARGET'] = self.NextLine()
        assert len(casedict['KBD']) == casedict['K']
        assert len(casedict['TARGET']) == casedict['L']

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
