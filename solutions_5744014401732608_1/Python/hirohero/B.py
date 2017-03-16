a = open('B-large.in','r').readlines()
f = open('B.out','w')
now = 0
tests =  int(a[now].strip())
now += 1
for test in range(tests):
    (b, m) = a[now].strip().split()

    now += 1
    b = int(b)
    m = int(m)
    res = [[0 for i in range(b + 1)] for i in range(b + 1)]
    can = [0 for i in range(b + 1)]
    tmp = 0
    i = b - 1
    while (i > 1):
        if (tmp == m):
            break
        tmp += 1
        res[i][b] = 1
        can[i] = 1
        if (tmp == m): break
        j = i + 1
        while (j < b):
            if tmp + can[j] <= m:
                res[i][j] = 1
                tmp = tmp + can[j]
                can[i] = can[i] + can[j]
            j += 1
        i -= 1
    if tmp < m:
        res[1][b] = 1
        tmp += 1
    if tmp != m:
        print >> f, "Case #" + str(test + 1) + ': IMPOSSIBLE'
    else:
        print >> f, 'Case #' + str(test + 1) + ': POSSIBLE'
        for j in range(i, b):
            if (j != 1):
                res[1][j] = 1
        for i in range(1, b + 1):
            print >> f, ''.join(str(res[i][j]) for j in range(1, b + 1))
        
f.close()
            
    
