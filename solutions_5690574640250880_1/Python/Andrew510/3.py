
import sys

infile = sys.stdin
#infile = open('in.txt', 'r')

def run(themap, R, C, n):
    if n == 0:
        return True

    if R == 1:
        x = 1
        while n > 0:
            themap[0][x] = '.'
            x += 1
            n -= 1
        return True
    elif C == 1:
        y = 1
        while n > 0:
            themap[y][0] = '.'
            y += 1
            n -= 1
        return True
    
    if n < 3:
        return False
        
    themap[0][1] = '.'
    themap[1][1] = '.'
    themap[1][0] = '.'
    n -= 3
        
    if n == 0:
        return True

#    if R == 2:
#        x = 2
#        while n > 0:
#            if n < 2: return False
#            themap[x][0] = '.'
#            themap[x][1] = '.'
#            x += 1
#            n -= 2
#        return True
#    if C == 2:
#        y = 2
#        while n > 0:
#            if n < 2: return False
#            themap[0][y] = '.'
#            themap[1][y] = '.'
#            y += 1
#            n -= 2
#        return True
    
    if n < 2:
        return False

    if R > 2:
        themap[2][0] = '.'
        themap[2][1] = '.'
        n -= 2
        if n == 0: return True
        if n < 2: return False
    
    if C > 2:
        themap[0][2] = '.'
        themap[1][2] = '.'
        n -= 2

    x = 3
    while x < C and n >= 2:
        themap[0][x] = '.'
        themap[1][x] = '.'
        x += 1
        n -= 2
    
    y = 3
    while y < R and n >= 2:
        themap[y][0] = '.'
        themap[y][1] = '.'
        y += 1
        n -= 2
    
    if n == 0:
        return True
    if R == 2 or C == 2:
        return False


    x = 2
    y = 2
    while n > 0:
        if themap[y][x] == '*':
            themap[y][x] = '.'
            n -= 1
        x += 1
        if x >= C:
            x = 0
            y += 1
    
    return True
    

T = int(infile.readline())
for t in range(T):
    print 'Case #%d:' % (t+1)
    R, C, M = map(int, infile.readline().split())

    themap = map(lambda x: ['*'] * C, range(R))
    n = R*C - M

    themap[0][0] = 'c'
    n -= 1

    if run(themap, R, C, n):
        for row in themap:
            print ''.join(row)

        cnt = 0
        for row in themap:
            for c in row:
                if c == '*':
                    cnt += 1
        if cnt != M:
            print 'uh oh %d vs %d' % (cnt, M)
    else:
        #print "Impossible %d %d %d (%d)" % (R, C, M, (R*C)-M)
        print "Impossible"

        
    
