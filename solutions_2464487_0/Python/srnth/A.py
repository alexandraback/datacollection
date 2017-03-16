
T=int(input())
for t in range(T):
    r,p=map(int,input().split())
    l=0
    k=1000000000000000008
    while(l<k):
        n=(l+k)//2
        #print(n)
        if (1+n)*(1+2*n+2*r)<p:
            l=n+1
        else:
            k=n
    n-=3
    n=max(n,0)
    while((1+n)*(1+2*n+2*r)<=p): n+=1
    print("Case #{}: {}".format(t+1,n))

