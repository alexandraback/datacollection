f=open('A-small-attempt1.in')
g=open('A-small.out','w')

T=int(f.readline())

for t in range(1,T+1):

    line=f.readline().split()
    A=int(line[0])
    Af=float(A)
    B=int(line[1])
    Bf=float(B)
    
    line=f.readline().split()
    p_list=[float(p) for p in line]

    Pr_old=float(1.0)
    Exp_old=1.0+Bf+1.0 # press enter and retype straight away


    for j in range(A-1,-1,-1):
        jf=float(j)
        #print j,A-j-1,p_list
        Pr = Pr_old * p_list[A-j-1]
        Exp = Pr * (-Bf-1.0) + 2.0*Bf - Af + 2.0 + 2.0*jf
        #print Exp,j,Pr
        if Exp < Exp_old:
            Exp_old = Exp
        Pr_old = Pr

    Exp=Exp_old

    print >>g, "Case #"+str(t)+": "+str(Exp)
    print "Case #"+str(t)+": "+str(Exp)        

f.close()
g.close()
