def getDimList(X):
    return [(w, X-w+1) for w in range(1,(X+1)/2+1)]

def WorstBlockWillCutBoardInHalf(X, R, C):
    # If the worst block will fit, you still need to see if it's going to cut the board in half in a bad way
    # The main example of this is the case where you use an S-shaped piece and you have a 2xn grid
    a = min(R,C)
    b = max(R,C)
    dims = getDimList(X)
    # print a, dims
    if a >= 2 and any([a == min(d) for d in dims]):
        return True
    else:
        return False

def worstBlockWillFit(X, R, C):
    a = min(R, C)
    b = max(R, C)
    # print a, b, getDimList(X)
    if all([x <= a and y <= b for (x,y) in getDimList(X)]):
        return True
    else:
        return False

g = open('D-large.in', 'r+b')
T = int(g.readline().strip())
for c in range(1,T+1):
    X, R, C = map(int,g.readline().strip().split())

    # if c != 22: continue

    # print "############################"
    # print X, R, C

    # 7+-ominoes can have the hole in the middle
    if X >= 7:
        # print "Case #%d: RICHARD (7+omino)" % c
        print "Case #%d: RICHARD" % c
        continue

    ## At this point, X <= 7

    # Gabriel must be able to fill in the grid in at all
    if R*C % X != 0:
        # print "Case #%d: RICHARD (mod)" % c
        print "Case #%d: RICHARD" % c
        continue

    ## At this point, X <= 7 and it is possible for the grid to be filled in

    if X in [1, 2]:
        # print "Case #%d: GABRIEL (1 or 2 block)" % c
        print "Case #%d: GABRIEL" % c
        continue

    if X in [3]:
        if min(R,C) == 1:
            print "Case #%d: RICHARD" % c
            continue
        else:
            print "Case #%d: GABRIEL" % c
            continue


    ## At this point, 4 <= X <= 6 and it is possible for the grid to be filled in

    if worstBlockWillFit(X, R, C):

        ## At this point:
        ##   - 4 <= X <= 6,
        ##   - it is possible for the grid to be filled in
        ##   - the worst-shaped block will fit into the grid

        if WorstBlockWillCutBoardInHalf(X, R, C):
            # print "Case #%d: RICHARD (4 vs 2xN, S-shaped)" % c
            print "Case #%d: RICHARD" % c
        else:
            # print "Case #%d: GABRIEL (worst block fit)" % c
            print "Case #%d: GABRIEL" % c
    else:
        # print "Case #%d: RICHARD (worst block did not fit)" % c
        print "Case #%d: RICHARD" % c

g.close()