t = input()

for tc in range(1, t+1):
    n = input()
    s = ""
    a = []
    for i in range(0,2501):
        a.append(0)
    for i in range(0,2*n-1):
        t = raw_input().split()
        for j in range(0,n):
            a[int(t[j])]+=1
    for i in range(1,2501):
        if a[i] % 2 == 1:
            s += str(i)+" "
        
    
    
    
            
    print "Case #%d: %s" % (tc,s[:-1])