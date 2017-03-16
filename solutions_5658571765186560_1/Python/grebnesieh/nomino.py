for c in xrange(input()):
    X, R, C = map(int, raw_input().split())
    if R > C: R, C = C, R
    pos = True
    if (R * C) % X != 0:
        pos = False
    else:
        if X == 3:
            if R < 2: pos = False
        elif X == 4:
            if R < 3: pos = False
        elif X == 5:
            if R < 3: pos = False
        elif X == 6:
            if R < 4: pos = False
        elif X == 7:
            if R < 4: pos = False
        elif X >= 8:
            pos = False
    print "Case #" + str(c + 1) + ":",
    print ["GABRIEL", "RICHARD"][not pos]
