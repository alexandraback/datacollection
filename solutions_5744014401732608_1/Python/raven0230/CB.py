from math import log as log
T = eval(input())
for t in range(1,T+1):
    N = list(map(int,input().split(' ')))
    B = N[0]
    M = N[1]
    G = [[0 for range in range(B)] for i in range(B)]
    Max = pow(2,(B-2))
    diff = Max-M
    if (M > Max):
        print("Case #{}: IMPOSSIBLE".format(t))
        continue
    else: print("Case #{}: POSSIBLE".format(t))
    for i in range(B-1):
        for j in range(i+1,B):
            G[i][j] = 1
    s = Max/2
    i = 2
    while(diff != 0):
        if (diff-s >= 0):
            G[-i][-1]=0
            diff -= s
        s /= 2
        i += 1
    for i in range(B):
        for j in range(B):
            print(G[i][j],end='')
        print()
            
        
