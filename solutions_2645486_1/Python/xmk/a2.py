
f=open("input")
ff=open("output", "w")
readint=lambda :int(f.readline())
readintarray=lambda :map(int, f.readline().split())
T=readint()


for casex in range(T):
    E,R,N = readintarray()
    v=readintarray()
    need=[R]*(N+1)
    limit=[E]*N
    u=[R]*N
    vp=sorted([(x,i) for i,x in enumerate(v)], reverse=1)
    for x,i in vp:
        u[i]=min(limit[i], limit[i]-need[i+1]+R)
        n=limit[i]
        j=i
        while j>=0 and n>=R:
            need[j]=max(need[j],n)
            n-=R
            j-=1
        n=limit[i]-u[i]+R
        j=i+1
        while j<N and n<=E:
            limit[j]=min(limit[j],n)
            
            n+=R
            j+=1
        
    #print E,R,N
    #print "vp",vp
    #print "need",need
    #print "u",u
    rtn=sum(u[i]*v[i] for i in range(N))
    #print rtn
    print >>ff,"Case #%d:"%(casex+1),rtn
ff.close()
print "done"
"""
   i=1 to n
   (2*r+2*n-1)*n<=t
   2*n*n+(2*r-1)*n - t <=0

n=    -(2*r-1)+sqrt( (2*r-1)^2 + 4*2*t) /4
   

   2*(r+2*(i-1))+1 <=t
"""
