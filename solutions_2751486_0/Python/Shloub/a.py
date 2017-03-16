def cons(s):
    return not s in ['a', 'e', 'i', 'o', 'u']

for i in range(int(raw_input())):
    l=raw_input().split()
    s,n=l[0],int(l[1])
    rcons=[]
    ncons=0
    for j,x in enumerate(s):
        if cons(x):
            ncons+=1
        else:
            ncons=0
        if ncons>=n:
            rcons.append((j-n+1,j))
    r=0
    # print rcons
    for j in range(len(s)):
        for k in range(j,len(s)):
            # print j,k
            t=False
            m=0
            while not t and m<len(rcons):
                t=(k>=rcons[m][0]>=j) and (k>=rcons[m][1]>=j)
                m+=1
            if t:
                r+=1
    print"Case #"+str(i+1)+":",r
