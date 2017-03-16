#/usr/local/bin/python

import sys

T = int(sys.stdin.readline())

players = ["X", "O"]
dirs = ["R", "C", "D"]

def solve(board, direction):
    start = [ (x, 0) for x in xrange(4) ]
    dirx  = 0
    diry  = 1

    if direction == 2:
        start = [(0, 0), (0, 3)]
        dirx = diry = 1
    elif direction == 1:
        start = [ (0, x) for x in xrange(4) ]
        dirx  = 1
        diry  = 0

    is_empty = False

    for p in start:
        char = None
        found = True 
        line = ""

        if direction == 2 and p[1] == 3:
            diry = -1

        for i in xrange(4):
            ix = (p[0] + i * dirx) % 4
            iy = (p[1] + i * diry) % 4
            line += board[ix][iy]
            if board[ix][iy] == '.':
                found = False
                is_empty = True
                break
            elif board[ix][iy] != 'T':
                if char is None:
                    char = board[ix][iy]
                elif char != board[ix][iy]:
                    found = False


        if found:
            if char == "X":
                return 1
            else:
                return 2
    if is_empty:
        return -1

    return 0


for caseno in xrange(T):
    board = [ ]

    if caseno:
        sys.stdin.readline()

    for x in xrange(4):
        board.append(list(sys.stdin.readline().strip()))

    answer = None
    for x in xrange(3):
        new_ans = solve(board, x)

        if new_ans > 0:
            answer = new_ans
            break;
        elif new_ans == -1:
            answer = new_ans

    res = "Draw"

    if answer > 0:
        res = "%s won" % (players[answer - 1])
    elif answer == -1:
        res = "Game has not completed"

    print "Case #%d: %s" % (caseno + 1, res)
