import sys
from math import floor, sqrt

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    moves = ""
    (X, Y) = [int(i) for i in f.readline().split()]
    (x, y) = (0, 0)
    (flip_x, flip_y) = (X < 0, Y < 0)
    (X, Y) = (abs(X), abs(Y))
    flip_xy = X > Y
    if flip_xy:
        X, Y = Y, X
    counter = 0

    def flip(move):
        ret = move 
        if flip_xy:
            ret = ret.replace("E", "!")
            ret = ret.replace("N", "E")
            ret = ret.replace("!", "N")

            ret = ret.replace("W", "!")
            ret = ret.replace("S", "W")
            ret = ret.replace("!", "S")
        if flip_x:
            ret = ret.replace("E", "!")
            ret = ret.replace("W", "E")
            ret = ret.replace("!", "W")
        if flip_y:
            ret = ret.replace("N", "!")
            ret = ret.replace("S", "N")
            ret = ret.replace("!", "S")
        return ret

    # phase 1 - equalize X
    while (counter + 1) < 2 * (X - x):
        counter += 1
        x += counter
        moves += flip("E")

    # phase 2 - line up x
    while x != X:
        if x < X:
            reps = int(floor(sqrt(X - x)))
            moves += flip("W") * reps + flip("E") * reps
            x += reps ** 2
            counter += reps * 2
        elif x > X:
            reps = int(floor(sqrt(x - X)))
            moves += flip("E") * reps + flip("W") * reps
            x -= reps ** 2
            counter += reps * 2

    # phase 3 - equalize Y
    while (counter + 1) < 2 * (Y - y):
        counter += 1
        y += counter
        moves += flip("N")

    # phase 4 - line up y
    while y != Y:
        if y < Y:
            reps = int(floor(sqrt(Y - y)))
            moves += flip("S") * reps + flip("N") * reps
            y += reps ** 2
            counter += reps * 2
        elif y > Y:
            reps = int(floor(sqrt(y - Y)))
            moves += flip("N") * reps + flip("S") * reps
            y -= reps ** 2 
            counter += reps * 2

    print "Case #%d: %s" % (case + 1, moves)
    sys.stdout.flush()
