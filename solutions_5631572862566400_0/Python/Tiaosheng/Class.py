file = open('C-small-attempt0.in', 'r')
file2 = open('C-small-attempt0.out', 'w')

n=int(file.readline())

for i in range(n):

    m=int(file.readline())
    t=[int(i)-1 for i in file.readline().split()]
    def temp(x):
        seen=[0]*m
        d=x
        v=0
        while not seen[x]:
            seen[x]=1
            x=t[x]
            v+=1
        if x==d:
            return(v)
        else:
            return(1)



    def boucle(x):
        d=x
        mi=x
        seen=[0]*m
        while 1:

            x=t[x]
            mi=min(mi,x)
            if t[t[x]]==x:
                return(-1)
            if x==d:
                return(mi)
            if seen[x]:
                return(-1)
            seen[x]=1



    def duet(x):
        return(t[t[x]]==x)



    def fil(x):
        v=0

        while 1:
            if duet(x):
                return([v,x,t[x]])
            if boucle(x)!=-1:
                return(False)
            x=t[x]
            v+=1




    d=[duet(j) for j in range(m)]
    b=[boucle(j) for j in range(m)]

    f=[fil(j) for j in range(m)]

    x=[[0,b.count(j)][j!=-1] for j in b]
    a=max(x)

    nbDuet=int(sum(d)/2)

    t=[x for x in f if x]
    best=min(nbDuet*2,4)
    if t:
        t.sort(key=lambda x:-x[0])
        v,a,b=t[0]
        for x in t[1:]:
            vx,ax,bx=x
            if a!=ax and b!=bx:
                if a==bx:
                    best=max(best,2+v+vx)
                else:
                    best=max(best,4+v+vx)

    file2.write("Case #"+str(i+1)+": "+str(max(a,best))+"\n")
