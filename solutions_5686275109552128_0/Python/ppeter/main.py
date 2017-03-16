__author__ = 'Peter'
import numpy as np
import math

maxP=9
with open ("B-small-attempt2.out","w") as outF:
    with open("B-small-attempt2.in","r") as inF:
        nt= int(inF.readline())
        for t in xrange(nt):
            d= int(inF.readline())

            pcs= map(int,inF.readline().split())
            pArray= np.zeros(maxP+1,dtype=np.int32)
            for pc in pcs:
                pArray[pc]+=1
            costArray= np.zeros(maxP+1,dtype=np.int32)
            for pos in xrange(maxP+1):
                for pToCut in xrange(1,pos):
                    costArray[pToCut]+= pArray[pos]* (math.ceil(pos/float(pToCut))-1)
            currErg=maxP
            for pos in xrange(1,maxP+1):
                if costArray[pos]+pos<currErg:
                    currErg=costArray[pos]+pos
            outF.write("Case #%d: %d\n"%(t+1,currErg))


