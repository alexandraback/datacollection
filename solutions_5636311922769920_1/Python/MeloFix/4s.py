T = int(input())


for loopC in range(1,1+T):
    K, C, S = map(int,input().split())

    ans = []
    
    if C == 1:
        if S < K:
            ans = ["IMPOSSIBLE"]
        else:
            ans = list(range(1,K+1))
    elif S+1 < K:
        ans = ["IMPOSSIBLE"]
    elif K == 1:
        ans = [1]
    else:
        for x in range(K-1):
            ans.append(2 + x*(K+1))

    print("Case #{}: ".format(loopC), end=" ")
    for x in ans:
        print(x,end=" ")
    print()
        
    
        
