f=open('B-small-attempt0.in')
g=open('B-small-attempt0.out','w')

T=int(f.readline())

for t in range(1,T+1):

    N=int(f.readline())

    a=[]
    b=[]
    y=0
    #print N
    for n in range(N):
        ab=f.readline().split()
        a.append(int(ab[0]))
        b.append(int(ab[1]))
        #print a

    if (0 in a) or (0 in b):

        undone_twostars=range(N)        
        stars=0        
        doable_twostars=[]
             
        while(undone_twostars):

            for n in range(N):
                if b[n] <= stars:
                    doable_twostars.append(undone)

            for undone in undone_twostars:
                if undone in doable_twostars:
                    undone_twostars.remove(undone)
                    stars=stars+2
                    y=y+1
                elif doable_twostars:
                    stars=stars+2
                    y=y+1
                else:
                    stars=stars+1
                    y=y+1
        
        print >>g, "Case #"+str(t)+": "+str(y)

    else:
        print >>g, "Case #"+str(t)+": Too Bad"
f.close()
g.close()
