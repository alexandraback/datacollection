for t in range(int(raw_input())):
    d = [int(j) for j in raw_input().split(' ')]
    n, m = d[0], d[1]
    
    a = []
    for i in range(n): a.append([int(j) for j in raw_input().split(' ')])
    
    s = "YES"
    while n > 0 and s != "NO":
        changes = 0
        a_min = min([min(row) for row in a])
        temp_n = n
        for i in range(n-1, -1, -1):
            if a[i].count(a_min) == m:
                del a[i]
                temp_n -= 1
                changes += 1
        a = [[row[i] for row in a] for i in range(m)]
        n, m = m, temp_n
        temp_n = n
        for i in range(n-1, -1, -1):
            if a[i].count(a_min) == m:
                del a[i]
                temp_n -= 1
                changes += 1
        n = temp_n
        if changes == 0: s = "NO"
            
    print "Case #%d: %s" % (t+1, s)
