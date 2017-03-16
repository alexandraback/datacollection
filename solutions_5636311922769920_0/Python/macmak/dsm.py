T = int(input())

for case in range(T):
    K,C,S = map(int,input().split())
    m = K**(C-1)
    ans = []
    for x in range(K):
        ans.append(x*m + 1)
    print('Case #'+str(case+1)+':',*ans)
