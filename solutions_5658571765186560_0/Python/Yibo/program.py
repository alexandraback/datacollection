#!/usr/bin/python2.7

f = open('input.txt', 'r')
T = int(f.readline())

def win():
    print "GABRIEL"

def lose():
    print "RICHARD"

def solve(X, R, C):
    min_rc = min(R, C)

    if (R * C) % X != 0 or X > 6:
        lose()
    elif X <= 2:
        win()
    elif X == 3:
        if min_rc < 2:
            lose()
        else:
            win()
    elif X == 4:
        if min_rc < 3:
            lose()
        else:
            win()
    elif X == 5:
        if min_rc < 3:
            lose()
        else:
            win()
    elif X == 6:
        if min_rc < 4:
            lose()
        else:
            win()
    else:
        raise ValueError("X: " + str(X))

for t in range(T):
    (X, R, C) = f.readline().rstrip().split(' ')
    X = int(X)
    R = int(R)
    C = int(C)

    print "Case #" + str(t + 1) + ":",
    solve(X, R, C)

