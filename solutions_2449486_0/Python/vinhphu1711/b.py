T = int(raw_input())

for t in xrange(T):
    N, M = [int(i) for i in raw_input().split()]
    
    lines = [ ]
    for n in xrange(N):
        lines.append([int(i) for i in raw_input().split()])
    
    # check if row contain all 1 -> set to 0
    for i in xrange(N):
        if 2 not in lines[i]: # all 1
            lines[i][:] = [0]*M # set to 0
    
    # check column
    for j in xrange(M):
        flag = True
        for i in xrange(N):
            if lines[i][j] == 2:
                flag = False
                break
        if flag : # all 1 (or 0)
            for i in xrange(N): # set row to 0
                lines[i][j] = 0
                
    # if there's no more 1: YES
    # else : NO
    
    flag = True
    for i in xrange(N):
        for j in xrange(M):
            if lines[i][j] == 1:
                flag = False
                break
        if not flag:
            break

    print 'Case #%d: %s' % (t+1, 'YES' if flag else 'NO')