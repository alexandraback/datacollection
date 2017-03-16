#import numpy as np
from itertools import combinations
myinf = "sample.txt"
myinf = "C-small-attempt0.in"
#myinf = "B-large-practice.in"

myout = open("output.txt",'wt')
#myout = open("output1.txt",'wt')
#myout = open("output2.txt",'wt')

#import sys
#sys.setrecursionlimit(2000)


myin = open(myinf,'rt').read().split('\n')
num_case = int(myin[0])
print(num_case)
for case_i in range(num_case):
    shift=case_i*2+1   
    C=int(myin[shift].split()[0])
    D=int(myin[shift].split()[1])
    V=int(myin[shift].split()[2])
    ds = [int(x) for x in myin[shift+1].split()]
    d=D
    print(C,D,V,ds)
    cnt=0
    for v in range(1,V+1):
        nds=[]
        exist=False
        for i in range(d):
            if ds[i]<v:
                nds+=[ds[i]]
            if ds[i]==v:
                exist=True
                break
        #print('nds1',nds)
        if not exist:
            nds = nds*C
            #print('nds2',nds)
            n=len(nds)
            for k in range(2,n+1):
                comb=[x for x in combinations(nds,k)]
                for com in comb:
                    #print(com)
                    if(sum(com)==v):
                        exist=True
                        break
                if exist:
                    break
                #print('comb',comb)
            if not exist:
                cnt+=1
                d+=1
                ds+=[v]
    
    print('cnt',cnt)
    myout.write("Case #%d: %d\n"%((case_i+1),cnt))

myout.close()    
