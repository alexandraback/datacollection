for cases in range(1, int(input()) + 1):
    B, M = list(map(int, input().split()))
    
    adj = [[0 for j in range(B)] for i in range(B)]
    
    ans = 'IMPOSSIBLE'
    cur = 0
    for i in range(B - 1):
        if(cur == M):
            ans = 'POSSIBLE'
            break
        else:
            adj[i][-1] = 1
            cur += 1
        
        for j in range(B - 1):
            if(cur == M):
                ans = 'POSSIBLE'
                break
            elif(i != j):
                adj[i][j] = 1
                adj[j][-1] = 1
                cur += 1
        if(ans == 'POSSIBLE'):
            break
    
    print('Case #%d:' % (cases,), ans)
    if(ans == 'POSSIBLE'):
        for line in adj:
            print(''.join([str(x) for x in line]))
