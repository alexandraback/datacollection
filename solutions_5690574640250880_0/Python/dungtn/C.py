from sys import argv

def mine_simple(mine,R,C,M):
    if M == 0:
        return False
    if (R*C - M) == 1:
        for i in xrange(R):
            mine[i] = ['*' for _ in xrange(C)]
        return True
    if R - M/C >= 2:
        for i in xrange(R-M/C,R):
            mine[i] = ['*' for _ in xrange(C)]
        if M % C != 0:
            if R - M/C >= 3 and C - M % C >= 2:
                for i in xrange(C-M%C,C):
                    mine[R-M/C-1][i] = '*'
                return True
            else:
                return False
        else:
            return True
    if C - M/R >= 2:
        for i in xrange(R):
            for j in xrange(C-M/R,C):
                mine[i][j] = '*'
        if M % R != 0:
            if C - M/R >= 3 and R - M % R >= 2:
                for i in xrange(R-M%R):
                    mine[i][C-M/R-1] = '*'
                return True
            else:
                return False
        else:
            return True
    return False

def mine_bott(mine,R,C,M):
    if M == 0:
        return True
    R0,C0 = len(mine),len(mine[0])
    if R == 3 and C == 3:
        if M > 1:
            return False
        if C0 > C and mine[R-1][C] == '.':
            return False
        if R0 > R and mine[R][C-1] == '.':
            return False
        mine[R-1][C-1] = '*'
        return True
    if R > 2:
        if M >= C:
            M -= C
            R -= 1
            for i in xrange(C):
                mine[R][i] = '*'
        elif M < R:
            if C > 2:
                if C == C0:
                    m = min(C-2, M)
                elif C > 3:
                    m  = min(C-3, M)
                if C == 0 or C > 3:
                    M -= m
                    R -= 1
                    for i in xrange(m):
                        mine[R][i] = '*'
            elif R <= 2 or C <= 2:
                return False
    elif C <= 2:
        return False
    return mine_left(mine,R,C,M)

def mine_left(mine,R,C,M):
    if M == 0:
        return True
    R0,C0 = len(mine),len(mine[0])
    if C > 2:
        if M >= R:
            M -= R
            C -= 1
            for i in xrange(R):
                mine[i][C] = '*'
        elif M < C:
            if R > 2:
                f = False
                if R == R0 or mine[R-1][0] == '*':
                    m = min(R-2,M)
                    f = True
                elif R > 3:
                    m  = min(R-3,M)
                    f = True
                if f:
                    M -= m
                    C -= 1
                    for i in xrange(m):
                        mine[i][C] = '*'
            elif C <= 2 or R <= 2:
                return False
    elif R <= 2:
        return False
    return mine_bott(mine,R,C,M)

f = open(argv[1], 'r')
T = int(f.readline()[:-1])
for case in xrange(1,T+1):
    R, C, M = map(int, f.readline()[:-1].split(' '))
    mine = [['.' for _ in xrange(C)] for _ in xrange(R)]

    print "Case #%d:" % case
    #print R,C,M
    possible = mine_simple(mine,R,C,M)
    if not possible:
        mine = [['.' for _ in xrange(C)] for _ in xrange(R)]
        possible = mine_bott(mine,R,C,M)
    if not possible:
        mine = [['.' for _ in xrange(C)] for _ in xrange(R)]
        possible = mine_left(mine,R,C,M)
    if possible:
        mine[0][0] = 'c'
        for i in xrange(R):
            print ''.join(mine[i])
    else:
        print 'Impossible'
        #for i in xrange(R):
            #print ''.join(mine[i])

