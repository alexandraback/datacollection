r = open('3.test')

T = int(r.readline().rstrip())

RICHARD = 'RICHARD'
GABRIEL = 'GABRIEL'

for t in range(1, T+1):
    X, R, C = map(int, r.readline().rstrip().split())

    if (R*C) % X != 0:
        winner = RICHARD
    elif X == 1 or X == 2:
        winner = GABRIEL
    elif X == 3:
        if R == 1 or C == 1:
            winner = RICHARD
        else :
            winner = GABRIEL
    elif X == 4:
        if R < 2 or C < 2:
            winner = RICHARD
        elif R < 4 and C < 4:
            winner = RICHARD
        elif min(R,C) == 2:
            winner = RICHARD
        else:
            winner = GABRIEL

    print 'Case #%d: %s' % ( t, winner)


