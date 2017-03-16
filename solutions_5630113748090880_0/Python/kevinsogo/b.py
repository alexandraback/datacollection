from collections import *


for cas in xrange(1,1+input()):
    n = input()
    rows = [tuple(map(int, raw_input().strip().split())) for i in xrange(2*n-1)]
    rows.sort()
    grid = [[0]*n for i in xrange(n)]
    ct = [[0]*n for i in xrange(n)]
    
    def subok(i,h,v,sk):
        # print
        # print 'trying', i, h, v
        # for I in xrange(n):
        #     for J in xrange(n):
        #         x = grid[I][J] if ct[I][J] else '.'
        #         print x,
        #     print

        if i == 2*n-1:
            # print 'done!'
            return True

        r = rows[i]
        # print 'row', r

        if h < n:
            good = True
            for j in xrange(n):
                if ct[h][j] and grid[h][j] != r[j]:
                    good = False
                else:
                    grid[h][j] = r[j]
                    ct[h][j] += 1


            if good:
                if subok(i+1,h+1,v,sk):
                    return True

            for j in xrange(n):
                if grid[h][j] == r[j]:
                    ct[h][j] -= 1

        if not sk and h+1 < n:
            good = True
            for j in xrange(n):
                if ct[h+1][j] and grid[h+1][j] != r[j]:
                    good = False
                else:
                    grid[h+1][j] = r[j]
                    ct[h+1][j] += 1


            if good:
                if subok(i+1,h+2,v,True):
                    return True

            for j in xrange(n):
                if grid[h+1][j] == r[j]:
                    ct[h+1][j] -= 1

        if v < n:
            good = True
            for j in xrange(n):
                if ct[j][v] and grid[j][v] != r[j]:
                    good = False
                else:
                    grid[j][v] = r[j]
                    ct[j][v] += 1


            if good:
                if subok(i+1,h,v+1,sk):
                    return True

            for j in xrange(n):
                if grid[j][v] == r[j]:
                    ct[j][v] -= 1

        if not sk and  v+1 < n:
            good = True
            for j in xrange(n):
                if ct[j][v+1] and grid[j][v+1] != r[j]:
                    good = False
                else:
                    grid[j][v+1] = r[j]
                    ct[j][v+1] += 1


            if good:
                if subok(i+1,h,v+2,True):
                    return True

            for j in xrange(n):
                if grid[j][v+1] == r[j]:
                    ct[j][v+1] -= 1

    assert subok(0,0,0,False)

    def rows_of_grid():
        for i in xrange(n):
            row = []
            for j in xrange(n):
                row.append(grid[i][j])
            yield tuple(row)
        for j in xrange(n):
            row = []
            for i in xrange(n):
                row.append(grid[i][j])
            yield tuple(row)

    (answer,) = (Counter(rows_of_grid()) - Counter(rows)).elements()

    print "Case #%s: %s" % (cas, ' '.join(map(str, answer)))