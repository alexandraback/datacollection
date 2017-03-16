#a = [int(i) for i in raw_input().split()]

def column(matrix, i):
    return [row[i] for row in matrix]

times = input()
for time in range(times):
    a = [int(i) for i in raw_input().split()]
    n,m = a[0], a[1]
    lawn = []
    rowmax = []
    colmax = []
    for row in range(n):
        a = [int(i) for i in raw_input().split()]
        lawn.append(a)
        rowmax.append(max(a))
    for col in range(m):
        colmax.append(max(column(lawn, col)))
#    print 'rowmax', rowmax
#    print 'colmax', colmax
    proper = True
    for i in range(n):
        if proper == False:
            break
        for j in range(m):
            if lawn[i][j] < rowmax[i] and lawn[i][j] < colmax[j]:
                proper = False
                break
    if proper:
        print 'Case #%d: YES' % (time+1)
    else: print 'Case #%d: NO' % (time+1)