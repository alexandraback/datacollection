import math
fin=open("bffin","r")
fout=open("bffout","w")
T=int(fin.readline())
for dummy in range(T):
    fout.write("Case #"+str(dummy+1)+": ")
    N=int(fin.readline())
    F=[int(x) for x in fin.readline().split()]
    F=[0]+F
    Clen=[0 for x in range(N+1)]
    Clink=[-1 for x in range(N+1)]
    D2Cycle=[-1 for i in range(N+1)]
    for i in range(1,N+1):
        if F[F[i]]==i:
 #           2Cycle.add(i)
            D2Cycle[i]=0      
            Clink[i]=i
    MaxCycle=0
    for i in range(1,N+1):
        if D2Cycle[i]==-1:
            K=0
            j=i
            Cache=set([])
            while D2Cycle[j]==-1 and j not in Cache:
                K+=1
                Cache.add(j)
                j=F[j]
            if D2Cycle[j]>=0:
                W=Clink[j]
                E=D2Cycle[j]
                D2Cycle[i]=K+E
                Clink[i]=W
                j=F[i]
                Clen[W]=max(Clen[W],K+E)
                while K>0:
                    K-=1
                    D2Cycle[j]=K+E
                    Clink[j]=W
                    j=F[j]
            elif D2Cycle[j]==-2:
                y=i
                while y!=j:
                    D2Cycle[y]=-2
                    y=F[y]
            elif j in Cache:
                a=F[j]
                count=1
                while a!=j:
                    count+=1
                    a=F[a]
                MaxCycle=max(MaxCycle,count)
                j=i
                for u in range(K+1):
                    D2Cycle[j]=-2
                    j=F[j]
            else:
                print 'WTF!!!!!\n'
    Ans=MaxCycle
    Buff=0
    for i in range(1,N+1):
        if D2Cycle[i]==0:
            Buff+= 1+Clen[i]
    Ans=max(Ans,Buff)
    fout.write(str(Ans)+'\n')
    print str(dummy+1)+':'+str(MaxCycle)+'\n'
    print Clink
fin.close()
fout.close()
            

                
    
