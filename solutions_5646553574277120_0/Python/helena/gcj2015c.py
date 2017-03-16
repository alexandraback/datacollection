T = int(input())
for t in range(1,T+1):
    c, d, v = map(int,input().split())
    a = list(map(int,input().split()))
    #a = a*c
    a.sort()
    ans = 0
    r = 0
    s = 0
    k = 1
    for i in range(d):
        while a[i] > s + 1:
            ans += 1
            s += c*(s+1)
            
        else:
            s += c*a[i]
            
        if s >=v:
            break  
    while s < v:
        ans += 1
        s += c*(s+1)        
    print('Case #'+str(t)+':', ans)
        