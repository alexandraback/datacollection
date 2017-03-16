import math
#K=12
#C=6

for case in range(1,int(input())+1):
    res = ""
    K,C,S=[int(s) for s in input().split(' ')]
    Smin=math.ceil(K/C)
    if S < Smin:
        res = "IMPOSSIBLE"
    else:
        idx=[i*C for i in range(0,Smin)]
        for s in range(0,Smin):
            for l in range(0,C-1):
                idx[s] = idx[s]*K+((idx[s]+1)%K)
        for i in idx:
            res += str(i+1) + " "
    print("Case #"+str(case)+": "+res)
