num_test = int(raw_input())
for test_case in xrange(1,num_test+1):

    l1, l2, l3, M = [int(k) for k in raw_input().split()]
    
    db = [{}, {}, {}]
    for i in xrange(1, l1+1):
       for j in xrange(1, l2+1):
           db[0][(i,j)] = 0
    for i in xrange(1, l1+1):
       for j in xrange(1, l3+1):
           db[1][(i,j)] = 0
    for i in xrange(1, l2+1):
       for j in xrange(1, l3+1):
           db[2][(i,j)] = 0
           
    sols = 0
    tab = []
    
    for i in xrange(1, l1+1):
        for j in xrange(1, l2+1):
            for k in xrange(1, l3+1):
                if db[0][(i, j)] < M and db[1][(i, k)] < M and db[2][(j, k)] < M:
                    sols += 1
                    tab.append(str(i)+' '+str(j)+' '+str(k))
                    db[0][(i, j)] += 1
                    db[1][(i, k)] += 1 
                    db[2][(j, k)] += 1 
            
    print "Case #{}: {}".format(test_case, sols)
    for row in tab:
        print row