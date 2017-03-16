T = int(input())
for t in range(1,T+1):
    r, c, w = map(int,input().split())
    ans = r*(c//w + w - 1)
    if c % w != 0:
        ans += 1
        
    print('Case #'+str(t)+':', ans)
        