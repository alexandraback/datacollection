from math import *
T=int(input())
for i in range(T):
    K,C,S=map(int,input().split())
    if K/C>S:
        print("Case #" + str(i+1) + ": IMPOSSIBLE")
    else:
        res = []
        nb_checked = 0
        k=1
        for j in range(K):
            k+=j*K**(C-nb_checked-1)
            nb_checked+=1
            if nb_checked == C:
                res+=[str(k)]
                k=1
                nb_checked=0
        if nb_checked !=0:
            res+=[str(k)]
        print("Case #" + str(i+1) + ": " + " ".join(res))
