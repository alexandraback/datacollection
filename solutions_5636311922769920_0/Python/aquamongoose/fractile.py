t = int(input())
for i in range(t):
    print('Case #{}: '.format(i+1), end='')
    K, C, S = map(int, input().split())
    if S*C >= K:
        for i in range((K+C-1)//C):
            s = sum(((i*C + j)%K)*K**j for j in range(C)) + 1
            print(s, end=' ')
        print()
    else:
        print('IMPOSSIBLE')
