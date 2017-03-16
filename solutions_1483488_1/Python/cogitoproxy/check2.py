f=open('a8','r')
f2=open('out','w')
numLines=int(f.readline().strip())

for i in range(0,numLines):
    ctr=0
    doneDict={}
    a,b=[int(tmpInt) for tmpInt in f.readline().strip().split(' ')]
    for n in range(a,b):
        if doneDict.has_key(n):
            continue
        strn=str(n)
        matchList=[n]
        for index in range(1,len(strn)):
            if strn[index]=='0' or strn[index]<strn[0] or strn[index]>str(b)[0]:
                continue
            newn=(strn[index:]+strn[:index])
            nin=int(newn)
            doneDict[nin]=1
            if len(newn)==len(strn) and nin>=a and nin<=b and nin not in matchList:
                matchList.append(nin)
        if len(matchList)>1:
            ctr+=(len(matchList)*(len(matchList)-1))/2
    print ctr
    f2.write("Case #%d: %d\n" % (i+1,ctr))

f2.close()
