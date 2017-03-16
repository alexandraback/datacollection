#!/usr/bin/env python
import sys,os
import numpy as np


def Solve(A,B,K):
    s=0
    for i in xrange(0,A):
        for j in xrange(0,B):
            #print (i,j),':','0'+bin(i&j).lstrip('0b')
            if i&j<K: s+=1
    return s



def parse(infile):
    A,B,K=map(int, infile.readline().split() )
    return A,B,K


mytestcase="""paste test case here1"""

def test():
    import StringIO
    args=parse(StringIO.StringIO(mytestcase))
    Solve(*args)


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
        print 'Rename: %s -> %s'%(outname,oldout)   
 
    outfile=open(outname,'w')

    for iCase, args in myCases:
        answer=Solve(*args)

        print 'Case #'+str(iCase)+':',answer
        print >> outfile, 'Case #'+str(iCase)+':',answer




if __name__=='__main__':
    if sys.argv[1]=='-test':
        test()
    else:
        runmain()
