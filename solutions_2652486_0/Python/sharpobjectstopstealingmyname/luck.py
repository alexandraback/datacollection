T = int(raw_input())

unit = 1/8.0
p = [[[[0]*200 for x in xrange(6)]for y in xrange(6)] for z in xrange(6)]
for x in xrange(2,6):
    for y in xrange(2,6):
        for z in xrange(2,6):
            p[x][y][z][1] += unit
            p[x][y][z][x] += unit
            p[x][y][z][y] += unit
            p[x][y][z][z] += unit
            p[x][y][z][x*y] += unit
            p[x][y][z][x*z] += unit
            p[x][y][z][y*z] += unit
            p[x][y][z][x*y*z] += unit

for qq in xrange(1,T+1):
    r,n,m,k = map(int,raw_input().split(" "))
    print "Case #1:"
    for case in xrange(r):
        stuff = map(int, raw_input().split(" "))
        best = "222"
        score = 0
        for x in xrange(2,6):
            for y in xrange(2,6):
                for z in xrange(2,6):
                    can_score = reduce(lambda a,b:a*b, map(lambda c: p[x][y][z][c], stuff))
                    if can_score > score:
                        score = can_score
                        best = str(x)+str(y)+str(z)
        print(best)
