filename  = "C-large.in"
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
for C in range(T):
    N=int(f.readline())
    F = [int(k) for k in f.readline().split()]
    #print(F)
    unliked  =[j for j in filter(lambda x: not (x in F),range(1,1+N))]
    #print("unliked "+str(unliked))
    #comp cycles:
    buddies  = [j+1 for j in range(N) if F[F[j]-1]==j+1]
    FT=[F[i] for i in range(N)]
    for k in range(1,N):
        FT = [FT[j] if isinstance(FT[j],str) or (FT[j]<0) else (-(k+1) if F[FT[j]-1]==j+1 else F[FT[j]-1])for  j in range(N)]
        maxCycle = -min(FT)
    #print("maxCycle :"+str(maxCycle))
    #buddies = [j for j in range(N) if FT[j]==-2]
    #print("buddies "+str(buddies))
    
    D = {}
    
    maxBuddy={k:0 for k in buddies}
    for j in unliked:
        #print("asdf")
        k=j
        it=0
        while (not (k  in buddies)) and it<N+1:
            #print("iter:"+str(k))
            k=F[k-1]
            it+=1
        #print("endloop:"+str(k))
        if k in buddies:
            D[j]=[k,it]
            if (it>maxBuddy[k]):
                maxBuddy[k]=it
    #print("UnDur "+str(D)) 
    #print("maxBuddy "+str(maxBuddy))
    L =[2+maxBuddy[k]+maxBuddy[F[k-1]] for k in buddies if F[k-1]>k]
    res = max(sum(L),maxCycle)
    out.write("Case #"+str(C+1)+": "+str(res)+"\n")
    print("Case "+str(C+1)+": "+str(res))
    
    
            
f.close()
out.close()
