#!/usr/bin/python
import sys, collections, copy

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))
CACHE = {}
BOARD = collections.defaultdict(int)

def sgood(OR,OC,R,C,M):
    if (R,C,M) in CACHE:
        return CACHE[(R,C,M)]
    if R == 1 or C == 1:
        return False
    if M <= ((R-2) * (C - 2)) and C > 2 and R > 2:
        while M >= C - 2:
            M = M - (C - 2)
            for i in xrange(0,C-2):
                BOARD[(OR,OC+i)] = 1
            OR = OR + 1
        for i in xrange(0,M):
            BOARD[(OR,OC+i)] = 1
        return True
#    if M <= (C * (R - 2)) and R > 2:
#        while M >= (R-2):
#            M = M - (R-2)
#            for i in xrange(0,R-2):
#                BOARD[(OR+i,OC)] = 1
#            OC = OC + 1
#        for i in xrange(0,M):
#            BOARD[(OR+i,OC)] = 1
#        return True
    if (C == 2 or R == 2) and (M % 2):
        return False
    if C == 2 and (M % 2 == 0) and M <= (2*(R - 2)):
        for i in xrange(0,M/2):
            BOARD[(OR+i,OC)] = 1
            BOARD[(OR+i,OC+1)] = 1
        return True
    if R == 2 and (M % 2 == 0) and M <= (2*(C - 2)):
        for i in xrange(0,M/2):
            BOARD[(OR,OC+i)] = 1
            BOARD[(OR+1,OC+i)] = 1
        return True
    if sgood(OR+1,OC,R-1,C,M-C):
        for i in xrange(0,C):
            BOARD[(OR,OC+i)] = 1
        return True
    if sgood(OR,OC+1,R,C-1,M-R):
        for i in xrange(0,R):
            BOARD[(OR+i,OC)] = 1
        return True
    CACHE[(R,C,M)] = 0
    return False

def good(R, C, M):
    global BOARD
    BOARD = collections.defaultdict(int)
    if R == 1:
        for i in xrange(0,M):
            BOARD[(0,i)] = 1
        return True
    if C == 1:
        for i in xrange(0,M):
            BOARD[(i,0)] = 1
        return True
    if M == (R*C) - 1:
        for i in xrange(0,R):
            for j in xrange(0,C):
                BOARD[(i,j)] = 1
        return True
    return sgood(0,0,R,C,M)
            
for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase
    (R, C, M) = [ int(x) for x in data.pop(0).split() ]
    v = good(R,C,M)
    if v:
        g = 0
        for i in xrange(0,R):
            s = ''
            for j in xrange(0,C):
                if i == R - 1 and j == C - 1:
                    s += 'c'
                    g = g + 1
                    
                elif BOARD[(i,j)]:
                    s += '*'
                else:
                    s += '.'
                    g = g + 1
                    
            print s
        if g != (R*C) - M:
            print R, C, M
            assert False
    else:
#        print 'Case #%d:' % numcase
#        print R,C,M
        print 'Impossible'




