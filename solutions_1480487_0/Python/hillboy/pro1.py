import sys

f1=open(sys.argv[1])
f1=f1.readlines()[1:]

i=0


for now in f1:
    i+=1
    print "Case #"+str(i)+":",
    now=now.split()[1:]
    now=map(int,now)
    a=sum(now)*1.0

    l=0.0
    r=2*a

    for j in range(0,1000):
        mid=(l+r)/2.0
        s=0.0
        for k in now:
           if k <= mid:
               s+=mid-k
        if s< a:
            l=mid
        else:
            r=mid
        
    b=l
    ans=""
    for j in now:
        if  b>= j:
            ans+=" "+str((b-j)/a*100.0)
        else:
            ans+=" 0"
        
    print ans
    
