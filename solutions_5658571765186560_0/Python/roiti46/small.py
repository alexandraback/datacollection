T = int(raw_input())
for loop in xrange(T):
    X, R, C = map(int, raw_input().split())
    if X >= 7 or R*C%X > 0:
        winner = 0
    elif X == 1 or X == 2:
        winner = 1
    elif X == 3:
        if min(R,C) == 1:
            winner = 0
        else:
            winner = 1
    elif X == 4:
        if min(R,C) <= 2:
            winner = 0
        else:
            winner = 1
    print "Case #%d: %s"%(loop+1, ["RICHARD","GABRIEL"][winner])
        
