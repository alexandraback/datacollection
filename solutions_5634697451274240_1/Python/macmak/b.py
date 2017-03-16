T = int(input())
for case in range(T):
    ps = input()
    ans = 0
    if ps[-1] == '-':
        ans += 1
    if len(ps) > 1:
        for i in range(len(ps)-1):
            if ps[i] != ps[i+1]:
                ans += 1
    print('Case #',case+1,': ',ans,sep='')
