import sys

def solve(tx, ty):
    moves = ""
    wx = wy = 1
    x = y = 0
    while x != tx and len(moves) < 500:
        # print("x: (%d,%d)" % (x,y))
        if x < tx:
            # direction change
            if wx < 0: wx = 1
            x += wx
            wx += 1
            moves += "E"
        else:
            # direction change?
            if wx > 0: wx = -1
            x += wx
            wx += -1
            moves += "W"
    while y != ty and len(moves) < 500:
        # print("x: (%d,%d)" % (x,y))
        if y < ty:
            # direction change
            if wy < 0: wy = 1
            y += wy
            wy += 1
            moves += "N"
        else:
            # direction change?
            if wy > 0: wy = -1
            y += wy
            wy += -1
            moves += "S"

    if len(moves) >= 500:
        print("too many moves!")
        sys.exit(1)
    return moves

numcases = int(sys.stdin.readline())
for c in range(numcases):
    x, y = [int(x) for x in sys.stdin.readline().split()]
    print("Case #%d: %s" % (c+1, solve(x,y)))
