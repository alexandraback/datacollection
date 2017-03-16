__author__ = 'peter'

import numpy as np

results=[]
with open("D-large.in","r") as inF:
    T= int(inF.readline())
    for iT in range(0,T):
        n= int(inF.readline())
        ABlocksOrig= map(float,inF.readline().split())
        BBlocksOrig= map(float,inF.readline().split())

        ABlocksOrig.sort()
        BBlocksOrig.sort()

        ABlocks= list(ABlocksOrig)
        BBlocks=list(BBlocksOrig)

        points0=0
        while True:
            if len(ABlocks)==0:
                break
            if ABlocks[-1]>BBlocks[-1]:
                points0+=1
                ABlocks.pop(-1)
                BBlocks.pop(-1)
            else:
                ABlocks.pop(0)
                BBlocks.pop(-1)

        ABlocks= list(ABlocksOrig)
        BBlocks=list(BBlocksOrig)

        points1= 0
        while True:
            if len(ABlocks)==0:
                break
            if ABlocks[-1]>BBlocks[-1]:
                points1+=1
                ABlocks.pop(-1)
                BBlocks.pop(0)
            else:
                for i in range(0,len(BBlocks)):
                    if BBlocks[i]>ABlocks[0]:
                        BBlocks.pop(i)
                        break
                ABlocks.pop(0)

        results.append("%d %d"%(points0,points1))

for iRes in range(0,len(results)):
    print "Case #%d: %s"%(iRes+1,results[iRes])