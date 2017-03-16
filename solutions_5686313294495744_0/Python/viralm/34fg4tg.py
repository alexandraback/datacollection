t=input()
for tc in xrange(0,t):
    template="Case #"+str(tc+1)+":"
    n=input()
    first=[]
    second=[]
    count=0
    for i in range(0,n):
        a,b=(i for i in raw_input().split())
        first.append(a)
        second.append(b)
    f=[]
    s=[]
    for i in xrange(0,n-1):
        #print i
        if i>=len(first)-1:
            break
        if ((((first[i] in first[0:i])==True) or ((first[i] in first[i+1:])==True)) and (((second[i] in second[0:i])==True) or ((second[i] in second[i+1:])==True))):
            #print first[i],second[i]
            #f.append(first[i])
            #s.append(second[i])
            first.pop(i)
            second.pop(i)
            count+=1
    i=len(first)-1
    if ((((first[i] in first[0:i])==True) or (False==True)) and (((second[i] in second[0:i])==True) or (False==True))):
        #print first[i],second[i]
        first.pop(i)
        second.pop(i)
        count+=1
##    for i in f:
##        first.remove(i)
##    if((a in first)==True and (b in second)==True):
##            count+=1
    print template,count
    
