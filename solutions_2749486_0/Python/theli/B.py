from sys import stdin

T = int(stdin.readline())
dirYmax = 'NSEW'
dirXmax = 'EWNS'
for i in xrange(1,T+1):
    X, Y = map(int, (x for x in stdin.readline().split()))
    if Y < X:
        X, Y = Y, X
        dirs = dirXmax
    else:
        dirs = dirYmax
    
    x,y = 0,0
    result = []
    d = 1
    while x != X or y != Y:
        if d == Y:
            result.append(dirs[0])
            y = Y
        elif d == -Y:
            result.append(dirs[1])
            y = Y
        elif (x < X) and (x + d <= X):
            result.append(dirs[2])
            x += d
        else:
            result.append(dirs[3])
            x -= d
        d += 1
        #print x,y

    result = ''.join(result)
    print 'Case #{0}: {1}'.format(i, result)
