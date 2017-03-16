def jinzhi(lst,n):
    lst.reverse()
    res=0
    for i in range(len(lst)):
        res+=(lst[i]-1)*n**i
    return res+1

file=open("D-large.in")
line=file.readline()
t=int(line[:-1])
outfile=open("output.txt","w")
for N in range(t):
    line=file.readline()
    line=line.split()
    [k,c,s]=line
    k=int(k)
    c=int(c)
    s=int(s)
    lst=[]
    for i in range(k):
        lst.append(i+1)
    f=0
    if k%c!=0:
        f=c-k%c        
    lst+=[1]*(f)
    nums=[]
    for i in range(k//c+(bool(f))):
        nums.append(lst[c*i:c*(i+1)])
    ans="case #"+str(N+1)+":"
    if len(nums)>s:
        ans+=" IMPOSSIBLE"
    else:
        for i in nums:
            ans+=" "+str(jinzhi(i,k))
    ans+="\n"
    outfile.write(ans)


outfile.close()

