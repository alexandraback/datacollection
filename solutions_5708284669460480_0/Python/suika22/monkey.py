#import numpy as np

myinf = "sample.txt"
myinf = "B-small-attempt0.in"
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
    
    shift=case_i*3+1   
    K=int(myin[shift].split()[0])
    L=int(myin[shift].split()[1])
    S=int(myin[shift].split()[2])
    kb = myin[shift+1]
    target = myin[shift+2]

    d={}
    for c in kb:
        if c in d:
            d[c]+=1
        else:
            d[c]=1

    e=S//L
    for i in range(1,L):
        rep=True
        for j in range(L-i):
            if target[j]!=target[i+j]:
                rep=False
                break
        if rep:
            e=(S-L)//i+1
            #print('===== e =====',S,L,i,e)
            break
                
    y=-1            
    p=1.
    for c in target:
        if c in d:
            p*=(d[c]/K)
        else:
            p=0.
            y=0
            break
    p*=(S-L+1)

    #print(K,S,L,d,p)
    if y==-1:
        y=e-p
    #print(kb,target)
    print("Case #%d: %.7f\n"%((case_i+1),y))
    myout.write("Case #%d: %.7f\n"%((case_i+1),y))

myout.close()    
