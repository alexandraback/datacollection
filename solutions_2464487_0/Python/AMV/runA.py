#!/usr/bin/env python
import sys,os
import numpy as np


def Solve(r,t):

    ilow=1

    ihigh=t

    while True:
        nRings=(ilow+ihigh)/2
        
        vn=VolNeeded(nRings,r)
        vn1=VolNeeded(nRings+1,r)

        if vn <= t < vn1:
            return nRings
        elif t<vn:
            ihigh=nRings
        else:
            ilow=nRings



def VolNeeded( nrings , r):
    return (nrings)*(2*r) + 4*Sum1ToN( nrings-1) + nrings
    


def Sum1ToN(N):
    return ((1+N)*N)/2


def parse(infile):
    r,t=map(int, infile.readline().split() )
    return r,t



class GCJ_Parser( object ):
    def __init__(self,fname):
        self.infile=open(fname,'r')
        self.NumCases=int(self.infile.readline().strip() )
        self.caseNum=0

    def __iter__(self): return self

    def next(self):
        if self.caseNum==self.NumCases: raise StopIteration
        self.caseNum += 1
        args=parse(self.infile)
        return self.caseNum , args


def runmain():
    myCases=GCJ_Parser(sys.argv[1])

    #Open output file, but don't overwrite old ones (for comparison)
    outname=sys.argv[1].rstrip('.in')+'.out'
    if os.path.isfile(outname):
        oldout=outname+'.old'
        ii=0
        while os.path.isfile(oldout):
            ii+=1
            oldout=outname+'.old'+str(ii)
        os.rename(outname,oldout)
    
    outfile=open(outname,'w')

    for iCase, args in myCases:
        answer=Solve(*args)

        print 'Case #'+str(iCase)+':',answer
        print >> outfile, 'Case #'+str(iCase)+':',answer



if __name__=='__main__':
    runmain()
