import sys
stdin = sys.stdin

def transpose(grid):
    re = [[grid[r][c] for r in range(len(grid))] for c in range(len(grid[0]))]
    return re

T = int(stdin.readline())
for tcase in range(T):
    r, c, m = map(int, stdin.readline().split())
    rc = r*c
    print 'Case #%d:' % (tcase+1)
    #print r, c, m
    if 1 == r or 1 == c:
        grid = ['.'] * max(r, c)
        grid[0] = 'c'
        for i in range(m):
            grid[-1-i] = '*'
        if r > 1:
            for it in grid:
                print it
        else:
            print ''.join(grid)

    elif 1 == rc-m:
        grid = [['*'] * c for i in range(r)]
        grid[0][0] = 'c'
        for row in grid:
            print ''.join(row)
    elif 2 == r or 2 == c:
        if rc-m < 4 or m % 2 == 1:
            print "Impossible"
            continue
        grid = [['.'] * 2 for i in range(max(r,c))]
        for i in range(m/2):
            grid[-1-i][0] = '*'
            grid[-1-i][1] = '*'
        if c > 2:
            #print 'Transposing grid'
            grid = transpose(grid)
        grid[0][0] = 'c'
        for row in grid:
            print ''.join(row)
    else:
        if rc-m < 4 or rc-m in [5, 7]:
            print "Impossible"
            continue
        grid = [['.'] * c for i in range(r)]
        grid[0][0] = 'c'
        if 4 == rc-m:
            grid = [['*'] * c for i in range(r)]
            grid[0][0] = 'c'
            grid[0][1] = '.'
            grid[1][1] = '.'
            grid[1][0] = '.'
            for row in grid:
                print ''.join(row)
        else:
            if r > c:
                grid = transpose(grid)
            mm = m / len(grid[0])
            h = len(grid) - mm
            if h < 3:
                h = 3
                mm = len(grid) - h
            m -= (len(grid)-h)*len(grid[0])
            for i in range(mm):
                grid[-1-i] = ['*'] * len(grid[0])
            mh = m / h
            for i in range(h):
                for k in range(mh):
                    grid[i][-1-k] = '*'
            m = m % h
            if h > 3 and m >= 2:
                grid[h-2][-mh-1] = '*'
                m -= 1
            for i in range(m):
                grid[h-1][-mh-1-i] = '*'
            if r > c:
                grid = transpose(grid)
            for row in grid:
                print ''.join(row)
