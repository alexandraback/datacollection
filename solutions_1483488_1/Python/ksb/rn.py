def process(a,b):
    bb = str(b)
    n = len(bb)
    ans = 0
    for k in range(a,b):
        s = str(k)
        t = s+s
        p = set()
        for i in range(1,n):
            p.add(t[i:i+n])
        for e in p:
            if e>s and e<=bb:
                ans += 1    
    return str(ans)


n = int(input())

for i in range(1,n+1):
    a,b = [int(x) for x in raw_input().split()]
    print "Case #"+str(i)+": "+process(a,b)
