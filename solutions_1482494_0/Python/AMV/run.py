#!/usr/bin/env python
import sys

infile=open(sys.argv[1],'r')

NumCases=int(infile.readline())

getone=lambda x:x[1]
getbiggesttwo=lambda x:x[2]
getsmallesttwo=lambda x:-x[2]

for iCase in xrange(NumCases):
    n=int(infile.readline().strip())

    level=[]
    for i in xrange(n):
        level.append( [0]+[int(i) for i in infile.readline().split() ] )

    canGetTwo=[l for l in level if l[2]==0]

    canGetOne=[l for l in level if l[1]==0 and l not in canGetTwo]

    notFinished=[]

    left=[l for l in level if l not in canGetOne and l not in canGetTwo]


    numStars=0
    numPlay=0
    while True:
#        print numStars,'b',canGetTwo,'a',canGetOne,'f',notFinished,'l',left
        change=False

        if len(canGetTwo)>0:
#            canGetTwo.sort(key=getone)
            canGetTwo.pop()
            numStars+=2
            change=True

        elif len(notFinished)>0:
            notFinished.sort(key=getsmallesttwo)
            if notFinished[-1][2]<=numStars:
                numStars+=1
                notFinished.pop()
                change=True
            
        if not change and len(canGetOne)>0:
            canGetOne.sort(key=getbiggesttwo)
            l=canGetOne.pop()
            l[0]=1
            notFinished.append(l)
            numStars+=1
            change=True

        if not change: break
        else:  numPlay+=1
            
            


        
        
        ii=0
        while ii<len(left):
            l=left[ii]
            if l[2]<=numStars:
                canGetTwo.append(l)
                left.pop(ii)
                continue

            elif l[1]<=numStars:
                canGetOne.append(l)
                left.pop(ii)
                continue

            ii+=1


        ii=0
        while ii<len(canGetOne):
            l=canGetOne[ii]
            if l[2]<=numStars:
                canGetTwo.append(l)
                canGetOne.pop(ii)
                continue
            ii+=1

        
        
    if numStars<2*n: answer='Too Bad'
    else: answer=numPlay

    print 'Case #'+str(iCase+1)+':',answer

