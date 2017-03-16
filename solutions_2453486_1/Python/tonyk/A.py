##fi = open('sample.in', 'r')
##fo = open('sample.out', 'w')
##fi = open('A-small-attempt0.in', 'r')
##fo = open('A-small-attempt0.out', 'w')
fi = open('A-large.in', 'r')
fo = open('A-large.out', 'w')

tc = int(fi.readline())
for i in range(tc):
    board = []
    completed = True
    for j in range(4):
        line = fi.readline()
        board.append([])
        for k in range(4):
            if line[k] == 'X':
                board[j].append(1)
            elif line[k] == 'O':
                board[j].append(-1)
            elif line[k] == 'T':
                board[j].append(0)
            else:
                board[j].append(20)
                completed = False
    fi.readline()

    sums = []
    for j in range(4):
        s1 = 0
        s2 = 0
        for k in range(4):
            s1 += board[j][k]
            s2 += board[k][j]
        sums.append(s1)
        sums.append(s2)

    s1 = 0
    s2 = 0
    for j in range(4):
        s1 += board[j][j]
        s2 += board[j][3 - j]
    sums.append(s1)
    sums.append(s2)

    if (3 in sums) or (4 in sums):
        fo.write('Case #' + str(i+1) + ': X won\n')
        continue

    if (-3 in sums) or (-4 in sums):
        fo.write('Case #' + str(i+1) + ': O won\n')
        continue

    if completed:
        fo.write('Case #' + str(i+1) + ': Draw\n')
        continue

    fo.write('Case #' + str(i+1) + ': Game has not completed\n')
fi.close()
fo.close()
