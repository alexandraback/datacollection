t=int(input())
for i in range (t):
    line1=input().split()
    C=line1[0]
    J=line1[1]
    allC=[""]
    allJ=[""]
    for j in range (len(C)):
        if C[j]=="?":
            newC=[]
            for a in allC:
                for k in range (10):
                    newC.append(a + str(k))
            allC=newC
        else:
            newC=[]
            for a in allC:
                newC.append(a+C[j])
            allC=newC
        if J[j]=="?":
            newJ=[]
            for a in allJ:
                for k in range (10):
                    newJ.append(a + str(k))
            allJ=newJ
        else:
            newJ=[]
            for a in allJ:
                newJ.append(a+J[j])
            allJ=newJ
    bestdiff=abs(int(allC[0])-int(allJ[0]))
    smallC=allC[0]
    smallJ=allJ[0]
    for a in allC:
        for b in allJ:
            c=int(a)
            j=int(b)
            diff = abs(c-j)
            if diff<bestdiff:
                bestdiff=diff
                smallC=a
                smallJ=b
            elif diff==bestdiff:
                if c<int(smallC):
                    smallC=a
                    smallJ=b
                elif c==int(smallC):
                    if j<int(smallJ):
                        smallJ=b
    
                



    print ("Case #" + str(i+1) + ": " + str(smallC) + " " + str(smallJ))
