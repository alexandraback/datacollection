import math
import heapq

class panState:
    def __init__(self, cdVals, sMoves=0):
        self.cdVals=cdVals
        self.curIndex=max(index for index in range(len(cdVals)) if cdVals[index]>0)
        self.sMoves=sMoves
        self.weight=self.curIndex+sMoves

    def __lt__(self, other):
        return self.cdVals<other.cdVals
        
    
    def split(self):
        ret=list()
        for val in [2,3,5,7,11,13,17,19,23,29,31,37]:
            if pow(val,2)<=self.curIndex:
                ret.append(self.splitOnVal(val))
            else:
                break
        return ret

    def splitOnVal(self,val):
        numAtIndex=self.cdVals[self.curIndex]
        div=int(self.curIndex/val)
        rem=self.curIndex-div*val
        atDiv=val-rem
        #(rem div+1s)*atCurIndex and (val-rem divs)*atCurIndex
        toChange=self.cdVals.copy()
        toChange[self.curIndex]=0
        toChange[div]+=numAtIndex*(atDiv)
        toChange[div+1]+=numAtIndex*(rem)
        newMove=(val-1)*numAtIndex+self.sMoves
        return panState(toChange,newMove)


path='C:\\CodeJam15\\QualificationRound\\data\\'
name='B-small-attempt1'
raw=open(path+name+'.in', 'r')
wrt=open(path+name+'.out','w')
numTrials=int(raw.readline())
for i in range(numTrials):
    numDiners=int(raw.readline())
    dinerCakeVals=list(int(s) for s in raw.readline().split())
    #convert to cakebased array
    cdSize=max(dinerCakeVals)
    cdVals=[0]*(cdSize+1)
    for val in dinerCakeVals:
        cdVals[val]+=1
    print(cdVals)
    pQ=[(0,panState(cdVals))]
    curState=heapq.heappop(pQ)
    minSol=curState[1].weight
    while curState[0]<minSol:
        minSol=min(minSol,curState[1].weight)
        for pS in curState[1].split():
            heapq.heappush(pQ,(pS.sMoves,pS))
        try:
            curState=heapq.heappop(pQ)
        except IndexError:
            break
    print(minSol)
    wrt.write('Case #'+str(i+1)+': '+str(minSol)+'\n')
wrt.close()



    
