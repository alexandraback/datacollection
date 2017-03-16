T = int(input())

for case in range(T):
    K,C,S = map(int,input().split())
    if C*S < K:
        print('Case #',case+1,': IMPOSSIBLE',sep='')
        continue
    checked = 0
    ans = []
    while checked < K:
        item = 0
        for ci in range(C):
            if checked < K:
                item += (checked) * (K**(C-ci-1))
            checked += 1
        ans.append(item + 1)
    print('Case #'+str(case+1)+':',*ans)
