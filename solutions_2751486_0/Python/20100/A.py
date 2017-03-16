def test(s,p,nb):
    rr=True
    for j in range(nb):
        if(s[j+p]=='a' or s[j+p]=='e' or s[j+p]=='i' or s[j+p]=='o' or s[j+p]=='u'):
            rr=False
    return rr

T=int(input())

for i in range(T):
    l=input().split()
    s=str(l[0])
    nb=int(l[1])
    r=0
    d=0

    for p in range(len(s)-nb+1):
        if(test(s,p,nb)):
            r+=(1+p-d)*(1+len(s)-p-nb)
            d=p+1
    
    print("Case #"+str(i+1)+": "+str(r))
