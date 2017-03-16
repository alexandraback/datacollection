def rev(a):
    b=0
    if a%10 == 0: return 10**9
    while a!=0:
        r=a%10
        b=b*10+r
        a=a/10
    return b
t=int(input())
ar=[0]*(1000005)
for t1 in range(1,t+1):
    n=int(input())
    ar[1]=1
    for i in range(2,n+1):
        z=rev(i)
        if z<i: ar[i]=min(ar[i-1],ar[z])+1
        else: ar[i]=1+ar[i-1]
    print "Case #%d: %d"%(t1,ar[n])
            
