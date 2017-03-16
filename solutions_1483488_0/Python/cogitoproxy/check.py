f=open('a7','r')
f2=open('out','w')
numLines=int(f.readline().strip())

for i in range(0,numLines):
    ctr=0
    doneList=[]
    a,b=[int(tmpInt) for tmpInt in f.readline().strip().split(' ')]
    for n in range(a,b):
        strn=str(n)
        for index in range(1,len(strn)):
            newn=(strn[index:]+strn[:index])
            nin=int(newn)
            if len(newn)==len(strn) and nin>n and nin>=a and nin<=b:
                if [n,nin] not in doneList:
                    ctr+=1
                else:
                    pass
                    #print n,nin
                doneList.append([n,nin])
    print ctr
    f2.write("Case #%d: %d\n" % (i+1,ctr))

f2.close()
