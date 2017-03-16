import sys

casenum = 1
def doit(lines):
    global casenum

    num_rows, num_cols = [int(x) for x in lines.pop(0).split(' ')]

    rows = []
    possible = []

    for i in range(num_rows):
        rows.append([int(x) for x in lines.pop(0).split(' ')])
        possible.append([False] * num_cols)

    cols = [[rows[i][j] for i in range(num_rows)] for j in range(num_cols)]

    for rownum in range(num_rows):
        rowmax = max(rows[rownum])

        for colnum in range(num_cols):
            if rows[rownum][colnum] == rowmax:
                possible[rownum][colnum] = True

    for colnum in range(num_cols):
        colmax = max(cols[colnum])

        for rownum in range(num_rows):
            if cols[colnum][rownum] == colmax:
                possible[rownum][colnum] = True

    # print num_rows, num_cols
    # print rows

    if all([all(possible_row) for possible_row in possible]):
        ans = 'YES'
    else:
        ans = 'NO'

    print 'Case #%d: %s' % (casenum, ans)
    casenum += 1

lines = [x.strip() for x in sys.stdin.readlines()]

ZZZ = int(lines.pop(0))
for case in range(ZZZ):
    doit(lines)
