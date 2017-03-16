from common import *

# No idea how to do this for the large test case, and the small test case is small
# enough to do every combination by hand

ok = [None] * 5
for x in range(5):
    ok[x] = [None] * 5
    for r in range(5):
        ok[x][r] = [False] * 5


# True means Gabriel wins

# 1-ominos are always tileable
# 2-ominos are tileable if there are an even number of squares
for r in range(5):
    for c in range(5):
        ok[1][r][c] = True
        if r * c % 2 == 0:
            ok[2][r][c] = True

# 3-ominos are tileable if it is 3x2, 3x3, or 3x4
ok[3][3][2] = True
ok[3][3][3] = True
ok[3][3][4] = True
ok[3][2][3] = True
ok[3][4][3] = True

# 4-ominos are tileable if it is 4x3 or 4x4
ok[4][4][3] = True
ok[4][3][4] = True
ok[4][4][4] = True

def main(casenum):
    x, r, c = readints()
    if ok[x][r][c]:
        writecase(casenum, 'GABRIEL')
    else:
        writecase(casenum, 'RICHARD')

run(main)
