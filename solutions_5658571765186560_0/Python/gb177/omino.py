#!/usr/bin/python

import sys
def N(): return tuple(map(int, raw_input().split()))

T = N()[0]
for t in range(1, T + 1):
    X, R, C = N()
    R, C = min(R, C), max(R, C)
    # wlog R <= C

    if X == 1:
        #  X
        bad = False
    elif X == 2:
        #  XX
        bad = R * C % 2 != 0
    elif X == 3:
        # XXX  XX
        #      X
        if C < 3 or R == 1 or R * C % 3 != 0:
            bad = True
        else:
            # 2x3 works
            # 3x3 works
            # 3x4 works
            bad = False
        #  -------------------------------
    elif X == 4:
        # XXXX XXX XXX XX   XX
        #      X    X   XX  XX
        # 
        if C < 4 or R == 1 or R * C % 4 != 0:
            bad = True
        else:
            if R == 2 and C == 4:
                bad = True
            if R == 3 and C == 4:
                # 1111 1222 1122 1133
                # 2222 1123 1122 2113
                # 3333 1333 3333 2223
                bad = False
            if R == 4 and C == 4:
                # can fill a smaller one, just add XXXX
                # 1111 1222 1122 1133
                # 2222 1123 1122 2113
                # 3333 1333 3333 2223
                # 4444 4444 4444 4444
                bad = False
            
    else:
        print >>sys.stderr, "Can only handle small case :-("

    print "Case #%d: %s" % (t, "RICHARD" if bad else "GABRIEL")

