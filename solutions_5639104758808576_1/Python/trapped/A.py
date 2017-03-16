T = int(raw_input())
for t in range(1,T+1):
    n,s = raw_input().split()
    n = int(n)
    s = map(int, s)
    
    cumsum = s[0]
    extra = 0
    for i in range(1,n+1):
        if s[i] == 0: continue
        if i <= cumsum: 
            cumsum += s[i]
            continue
        diff = i - cumsum
        cumsum += diff + s[i]
        extra += diff
    print "Case #%d: %d"%(t,extra)


