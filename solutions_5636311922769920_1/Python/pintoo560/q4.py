f = open('testcase', 'r')
f1 = open('ans', 'w')
tc=int(f.readline())
#print tc
for i in range(tc):
    nver=[1 for j in range(10)]
    k,c,s=map(int,f.readline().split())
    ans=''
    lev=min(k,c)   
    r=lev-1
    a=0
    p=r-1
    for l in range(1,r):
        a+=l*(k ** p)
        p-=1
    print a
    res=[]
    l=a+lev
    e=a+k
    while(l<=e):
        res.append(l)
        l+=1
    le=len(res)
    if(le<=s):
        ans=' '.join(str(res[i]) for i in range(le))
    else:
        ans='IMPOSSIBLE'   
        
    print res
    
    
       
    f1.write('Case #'+str(i+1)+': '+ans+'\n')

        
