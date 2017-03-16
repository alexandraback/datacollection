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

class UnionFind(object):
    def __init__(self, elements):
        self.partition = dict( (( (e,(e,1)) for e in elements )) )  
        # (element_id, leader_id, n_followers) - n_followers counts all the followers, but it only matters for leaders

    def find(self,v):
        """Find top leader of v = canonical representative of the equivalence class"""
        while True:
            leader = self.partition[v][0]
            if leader == v: 
                break
            v = leader

        return v

    def equiv(self, v, u):
        """Are v and u equivalend in this partition ? """
        return self.find(v) == self.find(u)

    def merge(self, v, u):
        """Merge v and u"""
        v_top_leader = self.find(v)
        u_top_leader = self.find(u)
        
        if v_top_leader == u_top_leader:
            return u_top_leader

        v_n_followers = self.partition[v_top_leader][1]
        u_n_followers = self.partition[u_top_leader][1]
        
        if v_n_followers > u_n_followers:
            self.partition[u_top_leader] = (v_top_leader, u_n_followers)
            self.partition[v_top_leader] = (v_top_leader, v_n_followers + u_n_followers)
            return v_top_leader
        else:
            self.partition[v_top_leader] = (u_top_leader, v_n_followers)
            self.partition[u_top_leader] = (u_top_leader, u_n_followers + v_n_followers)
            return u_top_leader

    def cluster_sizes(self):
        ret = {}
        for u in self.partition:
            l = self.find(u)
            ret.setdefault(l, 0)
            ret[l] += 1
        return ret.values()


def gen_free_ominoes(N):
    ominoes_dict = { 1: set([((0,0),)]) }
    for n in range(2,N+1):
        last_ominoes = ominoes_dict[n - 1]
        new_ominoes = set([])
        for omino in last_ominoes:
            DBG(omino)
            for x,y in omino:
                for dx, dy in (-1,0),(1,0),(0,-1),(0,1):
                    if (x+dx, y+dy) in omino: 
                        continue
                    new_ominoes.add( free_omino(omino + ((x+dx,y+dy),)) )
        ominoes_dict[n] = new_ominoes
    return ominoes_dict

def normalize_omino(om):
    min_x = min( [ x for (x,y) in om ] )
    min_y = min( [ y for (x,y) in om ] )
    return tuple(sorted([ ( x - min_x, y - min_y) for (x,y) in om]))

def flip(om):
    return normalize_omino([ (y, x) for (x,y) in om ] )

def inv(om,(fx,fy)):
    return normalize_omino([ (fx * x, fy * y) for (x,y) in om ] )

def free_omino(om):
    om1 = normalize_omino(om)
    ret = om1
    for fx in -1,1:
        for fy in -1, 1:
            for flp in lambda x:x, flip:
                ret = min(ret, flp( inv(om1, (fx,fy)) ) )
    return ret

def bbox(om):
    max_x = max( [ x for (x,y) in om ] )
    max_y = max( [ y for (x,y) in om ] )
    return max_x + 1,max_y + 1

def components(s):
    'components of an induced subgraph of Z^2'
    uf = UnionFind(s)
    for x,y in s:
        for dx, dy in (1,0),(-1,0),(0,1),(0,-1):
            if (x+dx, y+dy) in s:
                uf.merge( (x,y), (x+dx,y+dy) )
    return uf.cluster_sizes()

def sub_box(b1,b2):
    "if box b1 fits in box b2, with rotation"
    return ( min(b1) <= min(b2) ) and ( max(b1) <= max(b2) )

foms = gen_free_ominoes(6)

def normbox((x,y)):
    return (min(x,y), max(x,y))

def boxfits(om, (bx,by)):
    # can box of dim (bx, by) accomodate om with completion, and any motion ?
    bbx, bby = bbox(om)
    #DBG("checking fit",om,bx,by, "freedom=",bx -bbx,by-bby)
    X = len(om)
    if (bbx > bx) or (bby > by):
        return False
    if (bx * by) % X != 0: return False
    
    for dx in range(bx - bbx + 1):
        for dy in range(by - bby + 1):
            move_om = set([ (x+dx,y+dy) for (x,y) in om ])
            leftover_set = set([ (x,y) for x in range(bx) for y in range(by) if (x,y) not in move_om ])
            
            comps = components(leftover_set)

            if all( [ c % X == 0 for c in comps ] ):
                DBG('box',bx,by,'fits',om)
                return True

    return False 

def om_minboxes(om):
    # all minimal boxes that can accomodate om with completion
    check = set([])
    bbx, bby = bbox(om) 
    
    DBG("finding minboxes for om",om)
    for i in range(bby):
        S = ''
        for j in range(bbx):
            S += '*' if ((j,i) in om) else '.'
        DBG(S)

    X = len(om)
    for bx in range(bbx,bbx+2*X+2):
        for by in range(bby,bby+2*X+2):
            check.add( normbox((bx,by)) )
   
    DBG('check=',check)
    ret = set([])
    for (dx,dy) in check:
        if boxfits(om, (dx,dy) ) or boxfits(om,(dx,dy)):
            ret.add(normbox((dx,dy)))
    
    while True:
        brk = True
        for b1 in ret:
            if any( [ (b1 != b2) and sub_box(b2,b1) for b2 in ret ] ):
                brk = False
                ret.remove(b1)
                break
        if brk: 
            break

    ret = tuple(sorted(ret))
    DBG('sub boxes for',om,'are',ret)
    return ret


def minboxes(X):
    ret = set([])
    for om in foms[X]:
        ret.add(om_minboxes(om))
    return ret

minboxes = dict( [ (X,minboxes(X)) for X in range(1,7) ] )

class Case:
    def __init__(self, **ctx):
        self.__dict__.update( ctx )
        self.__ctx_names = ctx.keys()
        #self.pc = PreCalc(ctx) # precalc data
    
    def solve(self):
        DBG("in solve ", ' '.join( (( '%s=%s' % ( k, self.__dict__[k] ) for k in self.__ctx_names )) ) )
        X, R, C = self.X, self.R, self.C
        if X >= 7: 
            DBG('X>=7')
            return 'RICHARD'
        if (R * C) % X != 0: 
            DBG(' R*C mod X != 0')
            return 'RICHARD'
        for mbs in minboxes[X]:
            if all( [ not sub_box(bb, (R,C)) for bb in mbs ] ):
                DBG('no sub box in', mbs,'of ', (R,C))
                return 'RICHARD'
        return 'GABRIEL'

class ParsingMixIn:
    def ParseCase(self):
        casedict = dict(zip("XRC", self.NextTuple((long,long,long))))

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
