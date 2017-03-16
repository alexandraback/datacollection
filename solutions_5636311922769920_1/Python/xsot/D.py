def f(k, c, i=0):
    if c == 0:
        return i
    return i*k**c + f(k, c-1, i+1)

for t in range(1, int(raw_input())+1):
    k, c, s = map(int, raw_input().split())
    
    if k > 1 and s < k-c+1:
        print "Case #%d: IMPOSSIBLE" % t
        continue
    
    c = min(c, k)
    ans = f(k, c-1)
    
    a = []
    for i in range(k-c+1):
        a += [ans+i+1]
        
    print "Case #%d: " % t + " ".join(map(str, a))