T = int(input())

for test in range(T):
    B, M = tuple(map(int,input().split()))
    
    if M > 2**B:
        print('Case #' + str(test+1) + ': IMPOSSIBLE')
        continue
    else:
        print('Case #' + str(test+1) + ': POSSIBLE')
    
    links = [[0 for i in range(B)] for j in range(B)]
    
    for i in range(B):
        for j in range(B):
            if j == B - 1:
                links[i][j] = 1
            elif j == 0:
                links[i][j] = 0
            elif i == 0:
                if (B-1) & (2**(B - j - 2)) > 0:
                    links[i][j] = 1
                else:
                    links[i][j] = 0
            elif j > i:
                links[i][j] = 1
            else:
                links[i][j] = 0
        print(' '.join(map(str,links[i])))