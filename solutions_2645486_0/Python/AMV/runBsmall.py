#!/usr/bin/env python
import sys,os
import numpy as np


def Solve(E,R,N,vs):
    E_val={E:0}

    for iV in xrange(len(vs)):
        newEs={}
        for EEE in E_val:
            curval=E_val[EEE]
            for iUse in xrange(0,EEE+1):
                nextEnergy=min(EEE-iUse+R , E)
                newEs[ nextEnergy ] = max( curval+ iUse*vs[iV],
                                           newEs.get( nextEnergy, 0 ) )
        #print newEs
        E_val=newEs
            

    return max(newEs.values() )



def parse(infile):
    E,R,N=map(int, infile.readline().split() )
    vs=map(int, infile.readline().split() )
    return E,R,N,vs



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
