#!/usr/bin/env python
import sys,os
import numpy as np
import random
from itertools import chain,combinations

#hard coded parameters for small
N,M,K=3,5,7


def getSig(i,j,k):
    return ''.join( map(str, sorted( [i,j,k] ) ) )

def makeAllProds():
    canBe={}

    for i,j,k in ( (i,j,k) for i in xrange(2,M+1)
                   for j in xrange(2,M+1)
                   for k in xrange(2,M+1)):
        mysig=getSig(i,j,k)

        ps=list(powerset( [i,j,k] ))

        for p in ps:
            prod=np.product(p)

            canBe.setdefault( prod, set() ).add(mysig)
    return canBe


allsigs=[ getSig(i,j,k) for  i,j,k in ( (i,j,k) for i in xrange(2,M+1)
                                        for j in xrange(2,M+1)
                                        for k in xrange(2,M+1)) ]


def Solve(theproducts):
    possible=set(allsigs)

    for prod in theproducts:
        possible = possible.intersection( canBe[prod] )

    final=list(possible)
    if len(final)>1:
        return random.choice(final)
    else:
        return final[0]
    



def AllFactors(ddd):
    return [x for x in xrange(2,M+1) if ddd%x==0 ]


def Simulate():
    myset=[ random.randint( 2,M) for i in xrange(N) ]
    mysig=tuple(sorted( myset ) )
    myname=''.join( map(str,mysig))

    ps=list(powerset(myset))

    myprods=[ np.product( random.choice(ps)) for i in xrange(K)  ]

    theanswer=Solve(myprods)
    print theanswer==myname,theanswer,myname
    return theanswer==myname


def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))



def parse(infile):
    args=map(int, infile.readline().split() )
    return [ args ]



class GCJ_Parser( object ):
    def __init__(self,fname):
        self.infile=open(fname,'r')
        self.NumCases=int(self.infile.readline().strip() )
        self.NumCases=100
        self.caseNum=0
        self.params=map(int, self.infile.readline().split() )

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

    print 'Case #1:'
    print >> outfile,'Case #1:'
    for iCase, args in myCases:
        answer=Solve(*args)

        print answer
        print >> outfile, answer



def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))





class Counter(dict):
    def __init__(self,thelist,transform=None,trunc=2):
        dict.__init__(self)
        self.transform=transform
        self.trunc=trunc
        self.AddList(thelist)
    def AddList(self,thelist):
        if self.transform is not None:
            for item in thelist: self.Add( self.transform(item) )
        else:
            for item in thelist: self.Add( item )            
    def Add(self,object):
        if type(object) is float:
            object=round(object,self.trunc)
        if self.has_key(object):
            self[object]+=1
        else:
            self[object]=1
    def PrintRanking(self,n=None):
        if n is None: n=len(self)
        items=self.items()
        items.sort(key=lambda x:-x[1])
        total=0
        for i in items: total+=i[1]
        maxkey=max( len(str(key)) for key in self.iterkeys() )
        maxval=max( len(str(val)) for val in self.itervalues() )
        formatter="{0:<"+str(maxkey)+"} {1:>"+str(maxval)+"}    {2}"
        for key,count in items[0:n]:
            print formatter.format(key,count, ("%.2f"%(count*100.0/total))+'%')
    def Combine(self,newdict):
        newkeys=newdict.keys()
        for key in newkeys:
           if not type(newdict[key])==int:
              raise TypeError('passed object is not a counter')
        for key in newkeys:
           if not self.has_key(key): self[key]=0
           self[key] += newdict[key]
    def Avg(self):
        avg=0.0
        ntot=0
        for key in self.keys():
            ntot+=self[key]
            avg+=self[key]*key
        return avg/(1.0*ntot)
    def StdDev(self):
        avg=self.Avg()
        ntot=0
        stddev=0.0
        for key in self.iterkeys():
            ntot+=self[key]
            stddev += self[key] * ( (key-avg)**2)
        return stddev/(1.0*ntot)
    def Median(self):
 	total=sum(self.values())
        keys=self.keys()
        keys.sort()
        nCount=0
        for key in keys:
           nCount += self[key]
           if nCount>total/2: return key
    def Mode(self):
        return max(self.iteritems(), key=lambda x: x[1])[0]





canBe=makeAllProds()



if __name__=='__main__':
    runmain()













