path='C:\\CodeJam15\\Round1\\data\\'
name='C-large'
raw=open(path+name+'.in', 'r')
wrt=open(path+name+'.out','w')
numTrials=int(raw.readline())
for i in range(numTrials):
    numRepeats, numDoms, target= (int(s) for s in raw.readline().split())
    doms=list(int(s) for s in raw.readline().split())
    sol=0
    curCover=0
    curIndex=0
    curDom=doms[curIndex]
    while curCover<target:
        if curDom>curCover+1:
            sol+=1
            curCover=(curCover+1)*numRepeats+curCover
        else:
            if curIndex>=numDoms:
                print("Should never happen!")
            curCover=curDom*numRepeats+curCover
            curIndex+=1
            if curIndex<numDoms:
                curDom=doms[curIndex]
            else:
                curDom=target+1
    wrt.write('Case #'+str(i+1)+': '+str(sol)+'\n')
    #print(sol)
wrt.close()


    
