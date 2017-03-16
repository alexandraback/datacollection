def getDimList(X):
    return [(w, X-w+1) for w in range(1,(X+1)/2+1)]

def worstBlockWillFit(X, R, C):
    a = min(R, C)
    b = max(R, C)
    # print a, b, getDimList(X)
    if a == 2 and X == 4:
        return False
    if all([x <= a and y <= b for (x,y) in getDimList(X)]):
        return True
    else:
        return False

g = open('D-small-attempt1.in', 'r+b')
# g = open('input_4.txt', 'r+b')
T = int(g.readline().strip())
for c in range(1,T+1):
    X, R, C = map(int,g.readline().strip().split())

    # print "############################"
    # print X, R, C

    # 7+-ominoes can have the hole in the middle
    if X >= 7:
        # print "Case #%d: RICHARD (7+omino)" % c
        print "Case #%d: RICHARD" % c
        continue

    # Gabriel must be able to fill in the grid in at all
    if R*C % X != 0:
        # print "Case #%d: RICHARD (mod)" % c
        print "Case #%d: RICHARD" % c
        continue

    if X in [1,2]:
        # print "Case #%d: GABRIEL (1 or 2 block)" % c
        print "Case #%d: GABRIEL" % c
        continue

    if worstBlockWillFit(X, R, C):
        # In the case where you use an S-shaped piece and you have a 2xn grid
        if 2 in [R, C] and X == 4:
            # print "Case #%d: RICHARD (4 vs 2xN, S-shaped)" % c
            print "Case #%d: RICHARD" % c
        else:
            # print "Case #%d: GABRIEL (worst block fit)" % c
            print "Case #%d: GABRIEL" % c
    else:
        # print "Case #%d: RICHARD (worst block did not fit)" % c
        print "Case #%d: RICHARD" % c

g.close()