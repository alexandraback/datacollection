import sys

casenum = 1
def doit(data):
    global casenum

    rows = []
    for i in range(4):
        rows.append(data.pop(0))

    data.pop(0)

    lines = [row for row in rows]
    lines += [''.join([rows[i][j] for i in range(4)]) for j in range(4)]
    lines += [''.join([rows[i][i] for i in range(4)])]
    lines += [''.join([rows[i][3-i] for i in range(4)])]

    winner = None
    finished = True

    for line in lines:
        if line.replace("T", "X") == "XXXX":
            winner = "X"
            break

        if line.replace("T", "O") == "OOOO":
            winner = "O"
            break

        if "." in line:
            finished = False

    if winner == "X":
        ans = "X won"
    elif winner == "O":
        ans = "O won"
    elif finished:
        ans = "Draw"
    else:
        ans = "Game has not completed"

    print 'Case #%d: %s' % (casenum, ans)
    casenum += 1

raw = [x.strip() for x in sys.stdin.readlines()]

ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data)
