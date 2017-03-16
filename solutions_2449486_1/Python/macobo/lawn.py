from sys import stdin
def col(m, i):
    return [row[i] for row in m]

def row(m, i):
    return m[i]

def readInts():
    return (int(x) for x in stdin.readline().split())

def solve():
    rows, cols = readInts()
    target = [list(readInts()) for _ in range(rows)]
    ours = [[100] * cols for _ in range(rows)]
    for row_i in range(rows):
        mow_to = max(row(target, row_i))
        for col_i in range(cols):
            ours[row_i][col_i] = min(mow_to, ours[row_i][col_i])
    for col_i in range(cols):
        mow_to = max(col(target, col_i))
        for row_i in range(rows):
            ours[row_i][col_i] = min(mow_to, ours[row_i][col_i])
    if ours == target:
        return "YES"
    else:
        return "NO"


cases = int(stdin.readline())
for case in range(1, cases+1):
    print "Case #{}: {}".format(case, solve())