f=open("Money", "w")
T=input()
for i in range(T):
    C,D,V=[int(x) for x in raw_input().split()]
    a=[int(x) for x in raw_input().split()]
    b=[0 for x in range(V+1)]
    b[0]=1
    for j in a:
        k=len(b)
        while(k>j):
            k-=1
            b[k]+=b[k-j]
    f.write("Case #%d: %d\n"%(i+1,b.count(0)))

