__author__ = 'Peter'
import numpy as np
import math
import time
start=time.clock()
maxP=1000
with open ("B-large.out","w") as outF:
    with open("B-large.in","r") as inF:
        nt= int(inF.readline())
        for t in xrange(nt):
            d= int(inF.readline())

            pcs= map(int,inF.readline().split())
            pArray= np.zeros(maxP+1,dtype=np.int32)
            for pc in pcs:
                pArray[pc]+=1
            costArray= np.zeros(maxP+1,dtype=np.int32)
            for pos in xrange(maxP+1):
                if pArray[pos]==0:
                    continue
                for pToCut in xrange(1,pos):
                    costArray[pToCut]+= pArray[pos]* (math.ceil(pos/float(pToCut))-1)
            currErg=maxP
            for pos in xrange(1,maxP+1):
                if costArray[pos]+pos<currErg:
                    currErg=costArray[pos]+pos
            outF.write("Case #%d: %d\n"%(t+1,currErg))

end=time.clock()
print end-start

