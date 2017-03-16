DEBUG=0
PARALELL=1
TEST=0
SOLVE=1
################## TEMPLATE###################
import random
from pprint import pprint 
from collections import defaultdict
import heapq, struct

def prnt(x): 
    if DEBUG: 
        pprint(x)
if 'PyPy' not in copyright.__str__():
    PARALELL=0
if PARALELL:
    from multiprocessing import Process, cpu_count
    cpus=cpu_count()
    def poolmap(f,m, chunksize=None):return pool.map(f,m,chunksize)
else:
    cpus=1
    def poolmap(f,m, chunksize=None):return map(f,m)
def test():pass

################## TEMPLATE###################


def do(parent, root, DG):
    hijos=[]
    if len(filter(lambda x: x!=parent, DG[root]))<2:
        return 1
    
    for leaf in DG[root]:
        if leaf!=parent:
            hijos.append(do(root,leaf, DG))
    hijos.sort()
    r=sum(hijos[-2:])+1
    return r
from fractions import *
import copy
def do(s, constrain):
    sum=0
    empty=1
    for i in range(len(s)):
        c=s[i]
        if c[1]>0:
            empty=0
            car=c[0]
            const=copy.deepcopy(constrain)
            if const==None:
                const=(set(), None)
            
            c0, c1=const
            last=c1
            pass_constrain=1
            for x in car:
                if last != None and x!=last:
                    c0.add(last)
                if x in c0:
                    pass_constrain=0
                    break
                last=x
            c1=car[-1]
                
            if pass_constrain:
                ct=c[1]
                s[i][1]-=1
                
                sum+=do(s,(c0, c1)) * ct
                s[i][1]+=1
    
    if empty: return 1
    return sum%1000000007
        
    pass
def solve(INPUT):
        f=INPUT
        f.sort()
        print f
        ff=[]
        for  s in f:
            ss=[]
            last=None
            
            for x in s:
                if x!=last:
                    ss.append(x)
                last=x
            ns=''.join(ss)
            for x in ns:
                if ns.count(x)>1:
                    return 0
            ff.append(ns)
        s=[]
        
        last=None
        print 'ff',ff
        for x in ff:
            if x!=last:
                s.append([x, 1])
            else:
                s[-1][1]+=1
            last=x
        print 's',s
            
            
        print 'start',s
        r=do(s, None)%1000000007
        print 'stop',s
        return str(r)
def readit(t):
        f=getStrings()
        f=getStrings()
        return f

def run():
    T=getInt()
    INPUT=map(readit, range(T))
    answers=poolmap(solve,  INPUT)
    
    for t in range(T):
        outputFile.write( "Case #%d: %s\n"%(t+1,answers[t]))
    outputFile.close()
############# TEMPLATE ##########
 
import os
filename= os.path.basename(__file__)[:-3]
def getFloat():
    r=inputFile.readline()
    try:
        r= float(r)
        if DEBUG:
            print 'getFloat: ', r
        return r
    except:
        print 'Error parsing %r'%r
        raise
def getInt():
    r=inputFile.readline()
    try:
        r= int(r)
        if DEBUG:
            print 'getInt: ', r
        return r
    except:
        print 'Error parsing %r'%r
        raise
def getInts():
    return map(int,getStrings())
def getFloats():
    return float(int,getStrings())
def getStrings():
    r=inputFile.readline().split()
    if DEBUG:
        print 'getStrings: ', r
    return r

inputFile=file('%s.in'%filename, 'r')
outputFile=file('%s.out'%filename, 'w')

if __name__=='__main__':
    if PARALELL:
        from multiprocessing import Pool
        pool=Pool()
        
    if TEST:
        test()
    if SOLVE:
        run()
