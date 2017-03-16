from copy import copy
def solve (n,na,ke):
    
    na.sort(); na.reverse()
    ke.sort(); ke.reverse()
    na_c=copy(na)
    ke_c=copy(ke)
    w=0 ; dw=0;
    while (len(na)>0):
        if na[0]>ke[0]:
            del ke[len(ke)-1]
            del na[0]
            w+=1
        else:
            del na[0]
            del ke[0]
    na_c.reverse() ; ke_c.reverse()
    while (len(na_c)>0):
        if na_c[0]<ke_c[0]:
            del ke_c[len(ke_c)-1]
            del na_c[0]
        else:
            del na_c[0]
            del ke_c[0]
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