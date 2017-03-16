def calc(ss):
    total = sum(ss)
    n = len(ss)
    K = 2.0 * total / n
    res = [(K - j)/total for j in ss]
    while any([i < 0 for i in res]):
        for i in xrange(len(res)):
            if res[i] < 0:
                K -= ss[i] / n
        
        for i in xrange(len(res)):
            if res[i] < 0:
                res[i] = 0
            else:
                res[i] = (K - ss[i])/total 
    
    return res

t = int(raw_input())
i = 1
while i <= t:
    ss = [int(x) for x in raw_input().split(' ')]
    
    ss = ss[1:]
    
    res = calc(ss)
    
    print "Case #%s:"%i,
    for j in res:
        print "%.6f"%(j*100.0),
    print ''
    
    
    i += 1
