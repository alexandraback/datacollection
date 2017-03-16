import numpy as np

def read_data():
    cases={}
    fin=open('input1.txt','r')
    flines=fin.readlines()
    fin.close()
    for i in range(1,len(flines)):
        cases[i]=[]
        line=flines[i].split()
        for temp in line:
            cases[i].append(int(temp))
    return cases
    
def write_results(cases):
    fout=open('output1.txt','w')
    for i in cases:
        r=solve_small_case(cases[i][1],cases[i][2])
        fout.write('Case #'+str(i)+': '+str(r[1])+'\n')
    fout.close()
    
#def solve_small_case2(C,W):
#    if C<W:
#        return 0,np.inf
#    if W==1:
#        return C,C
#    if W==C:
#        return 1,W
#    else:
#        C1=(C-1)/2
#        C2=C-1-C1
#        if C1<W and C2<W:
#            P1=small_case_known(C1,W-1)
#            P2=small_case_known(C2,W-1)
#        else:
#            P1=solve_small_case(C1,W)
#            P2=solve_small_case(C2,W)
#        S1=1+P1[0]+P2[1]
#        S2=1+P2[0]+P1[1]
#        if S1>S2:
#            return 1+P2[0]+P1[0],1+P2[0]+P1[1]
#        else:
#            return 1+P1[0]+P2[0],1+P1[0]+P2[1]
#            
#def small_case_known2(C,W):
#    if C<W:
#        return 0,np.inf
#    else:
#        return 1,W
        
def solve_small_case(C,W):
    if C<W:
        return 0,-np.inf
    if W==C:
        return 1,W
    if C<W*2:
        return 1,W+1
    else:
        C1=W-1
        C2=C-W
        P1=solve_small_case(C1,W)
        P2=solve_small_case(C2,W)
        S1=1+P1[0]+P2[1]
        S2=1+P1[1]+P2[0]
        if S1>S2:
            return 1+P1[0]+P2[0],1+P1[0]+P2[1]
        else:
            return 1+P1[0]+P2[0],1+P2[0]+P1[1]
        
        
        

        
    
    