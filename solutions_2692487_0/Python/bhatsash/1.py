import math
inp=open('A-small-attempt4.in','r')
test=int(inp.readline().rstrip('\n'))
for counter in range(1,test+1):
    list1=inp.readline().rstrip('\n').split(' ')
    orig=int(list1[0])
    num=int(list1[1])
    list2=inp.readline().rstrip('\n').split(' ')
    for i in range(len(list2)):
        list2[i]=int(list2[i])
    list2=sorted(list2)
    s=orig
    count=0
    other=[]
    if orig==1:
        print "Case #%d: %d"%(counter,num)
    else:
        i=0
        while i<(num):
            if s<=list2[i]:
                if s-1!=0:
                    s+=s-1
                else:
                    s+=1
                other.append(num-i+count)
                count+=1
            else:
                s+=list2[i]
                i=i+1
        if other!=[]:
            c=min(count,min(other))
        else:
            c=count
        print "Case #%d: %d"%(counter,c)
    
