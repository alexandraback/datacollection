def isoftype(s,val):
    global n1
    for i in range(0,n1):
        if s[i]!='?':
            if s[i]!=val[i]:
                return False
    return True
t=input()
for tc in xrange(0,t):
    template="Case #"+str(tc+1)+":"
    s1,s2=(i for i in raw_input().split())
    n1=len(s1)
    n2=n1
    ans1=0
    ans2=0
    l1=[]
    l2=[]
    l=[]
    minimum=999999999999999
    for i in xrange(0,1000):
        if len(str(i))>n1:
            break
        x=str(i)
        y=str(i)
        lx=len(x)
        ly=len(y)
        x='0'*(n1-lx)+x
        y='0'*(n2-ly)+y
        if isoftype(s1,x):
            l1.append(int(x))
        if isoftype(s2,y):
            l2.append(int(y))
    i=0
    j=0
    nl1=len(l1)
    nl2=len(l2)
    diff=999999999999
    while((i<nl1) and (j<nl2)):
        diff=abs(l1[i]-l2[j])
        if diff<minimum:
            minimum=diff
            ans1=l1[i]
            ans2=l2[j]
        if l1[i]==l2[j]:
            break
        elif l1[i]<l2[j]:
            i+=1
        else:
            j+=1
        if(((i<nl1) and (j<nl2))==False):
            break
        diff=abs(l1[i]-l2[j])
        if diff<minimum:
            minimum=diff
            ans1=l1[i]
            ans2=l2[j]
    i=0
    j=0
    nl1=len(l1)
    nl2=len(l2)
    diff=999999999999
    while((i<nl1) and (j<nl2)):
        diff=abs(l1[i]-l2[j])
        if diff==minimum:
            l.append([l1[i],l2[j]])
        if l1[i]==l2[j]:
            break
        elif l1[i]<l2[j]:
            i+=1
        else:
            j+=1
        if(((i<nl1) and (j<nl2))==False):
            break
        diff=abs(l1[i]-l2[j])
        if diff==minimum:
            l.append([l1[i],l2[j]])
    l.sort()
    x=str(l[0][0])
    y=str(l[0][1])
    lx=len(x)
    ly=len(y)
    x='0'*(n1-lx)+x
    y='0'*(n2-ly)+y
    print template,x,y
    
    
