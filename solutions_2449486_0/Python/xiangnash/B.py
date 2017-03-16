import sys

T = int(sys.stdin.readline())
for ca in xrange(1, T+1):
    [N, M] = [int(v) for v in sys.stdin.readline().split(" ")]
    lawn = []
    for row in xrange(N):
        lawn.append([int(v) for v in sys.stdin.readline().split(" ")])
    
    #print lawn
    
    row_higher = [[False for j in range(M)] for i in range(N)]
    col_higher = [[False for j in range(M)] for i in range(N)]
    for row in xrange(N):
        highest = 0
        for col in xrange(M):
            if lawn[row][col] > highest:
                highest = lawn[row][col]
        for col in xrange(M):
            if lawn[row][col] < highest:
                row_higher[row][col] = True
        
    for col in xrange(M):
        highest = 0
        for row in xrange(N):
            if lawn[row][col] > highest:
                highest = lawn[row][col]
        for row in xrange(N):
            if lawn[row][col] < highest:
                col_higher[row][col] = True
    
    #print row_higher
    #print col_higher
    
    #nn = 0
    #for row in xrange(N):
    #    for col in xrange(M):
    #        print "++", row_higher[row][col], col_higher[row][col], 
    #        if row_higher[row][col] and col_higher[row][col]:
    #            nn += 1
    #    print " "
    nn = sum([1 if row_higher[row][col] and col_higher[row][col] else 0 for row in range(N) for col in range(M)])
    #print nn
    
    print "Case #%d:" % ca,
    if nn > 0:
        print "NO"
    else:
        print "YES"
