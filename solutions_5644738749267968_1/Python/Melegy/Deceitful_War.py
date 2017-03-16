from copy import copy
def solve (n,na,ke):
    na.sort(); na.reverse()
    ke.sort(); ke.reverse()
    na_c=copy(na)
    ke_c=copy(ke)
    w=0 ; dw=0;
    na_ps=0 ;na_pe=len(na)-1;
    ke_ps=0; ke_pe=len(ke)-1;
    while (na_ps<=na_pe):
        if na[na_ps]>ke[ke_ps]:
            ke_pe-=1
            na_ps+=1
            w+=1
        else:
            na_ps+=1
            ke_ps+=1
    na_c.reverse() ; ke_c.reverse()
    na_ps=0 ;na_pe=len(na)-1;
    ke_ps=0; ke_pe=len(ke)-1;
    while (na_ps<=na_pe):
        if na_c[na_ps]<ke_c[ke_ps]:
            ke_pe-=1
            na_ps+=1
        else:
            na_ps+=1
            ke_ps+=1
            dw+=1
    return str(dw)+" "+str(w)
            
fin=open('../in','r') ; fout=open('../out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    print case
    n=int(fin.readline())
    na=[float(x) for x in fin.readline().strip().split(' ')]
    ke=[float(x) for x in fin.readline().strip().split(' ')]
    fout.write("Case #"+str(case)+": "+str(solve(n,na,ke))+"\n")