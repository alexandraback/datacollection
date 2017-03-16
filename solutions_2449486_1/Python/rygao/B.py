def possible(a, N, M):
    checkrow = [0]*M
    check = [checkrow[:] for i in xrange(N)]
    
    rowmax = [max(row) for row in a]
    for i in xrange(N):
        for j in xrange(M):
            if a[i][j] == rowmax[i]:
                check[i][j] = 1
                
    for j in xrange(M):
        col = [a[i][j] for i in xrange(N)]
        colmax = max(col)
        for i in xrange(N):
            if a[i][j] == colmax:
                check[i][j] = 1

    for row in check:
        for col in row:
            if not col:
                return False
    return True
                
            

f = open('B-large.in', 'r')
T = f.readline().strip()
T = int(T)

g = open('output-large.txt', 'w')

print 'T:', T
for i in xrange(T):
    N, M = f.readline().split()
    N, M = int(N), int(M)

    a = []
    for j in xrange(N):
        a.append([int(elt) for elt in f.readline().split()])

    if possible(a, N, M):
        g.write('Case #%d: YES\n' % (i+1))
    else:
        g.write('Case #%d: NO\n' % (i+1))


f.close()
g.close()
