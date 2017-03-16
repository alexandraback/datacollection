import sys


f = open(sys.argv[1], 'r')
T = int(f.readline())
for i in range(T):
    case = int(i) + 1
    line = f.readline().strip().split(' ')
    N, M = map(int, line)

    pattern = []
    for n in range(N):
        line = f.readline().strip().split(' ')
        pattern.append(map(int, line))

    if N == 1 or M == 1:
        print "Case #%s: YES" % case
        continue

    row_max = []
    for n in range(N):
        row_max.append(max(pattern[n]))

    col_max = []
    for m in range(M):
        column = [row[m] for row in pattern]
        col_max.append(max(column))

    possible = True
    for y in range(N):
        for x in range(M):
            value = pattern[y][x]
            if value < row_max[y] and value < col_max[x]:
                possible = False
                break 
        if not possible:
            break

    if possible:
        print "Case #%s: YES" % case
    else:
        print "Case #%s: NO" % case
