T = int(raw_input())

for t in xrange(T):
    N, M = [int(i) for i in raw_input().split()]
    
    lines = [ ]
    
    heights = set()
    for n in xrange(N):
        arr = [int(i) for i in raw_input().split()]
        lines.append(arr)
        heights.update(arr)
    
    # loop through height level, from small to big
    heights = list(heights)
    heights.sort()
    
    res = True
    for h in heights:
        # check if row contain all h or 0 -> set to 0
        for i in xrange(N):
            flag = True
            for j in xrange(M):
                if lines[i][j] != h and lines[i][j] != 0:
                    flag = False
                    break
            if flag: # all h or 0
                lines[i][:] = [0]*M # set to 0
    
        # check column
        for j in xrange(M):
            flag = True
            for i in xrange(N):
                if lines[i][j] != h and lines[i][j] != 0:
                    flag = False
                    break
            if flag : # all h (or 0)
                for i in xrange(N): # set row to 0
                    lines[i][j] = 0
                
        # if there's no more h: continue
        # else : NO
    
        for i in xrange(N):
            for j in xrange(M):
                if lines[i][j] == h:
                    res = False
                    break
            if not res:
                break
        
        if not res:
            break

    print 'Case #%d: %s' % (t+1, 'YES' if res else 'NO')