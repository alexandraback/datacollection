from sys import stdin
from numpy import *

def solve(R,C,E):
    # mine is default for each position
    mined = ones((R,C),dtype=bool)
    
    # special treatment for 1-row and 2-row field
    if R == 1:
        mined[0,:E] = False
        return mined
    elif E == 1:
        mined[0,0] = False
        return mined
    elif R == 2:
        if E%2 == 0 and E>2:
            mined[:,:E//2] = False
            return mined
        else:
            return None
    # general case, C >= R >= 3, E > 1
    else:
        good_ab = None
        for a in range(2, R+1):
            for b in range(2, C+1):
                if 2*(a+b-2) <= E and E <= a*b:
                    good_ab = a,b
        if good_ab is None:
            #print "!!!!", R, C, E
            assert E in [2,3,5,7]
            return None
        else:
            assert E not in [2,3,5,7]
        a,b = good_ab

        mined[:a,:2] = False
        mined[:2,:b] = False
        c = E - 2*(a+b-2)
        for x in range(2,a):
            for y in range(2,b):
                if c>0:
                    mined[x,y] = False
                    c -= 1
        return mined

T = int(stdin.readline())
for t in range(1,T+1):
    R, C, M = [int(word) for word in stdin.readline().strip().split()]
    E = R*C - M
    # empty fields

    transposed = (R > C)
    if transposed:
        R, C = C, R
    
    m = solve(R, C, E)

    print "Case #"+str(t)+":"
    #print R, C, E
    if m is None:
        print "Impossible"
    else:
        if transposed:
            m = m.T
        for i,line in enumerate(m):
            s_line = '';
            for j,entry in enumerate(line):
                if i==0 and j==0:
                    s_line += 'c'
                else:
                    s_line += '*' if m[i,j] else '.'
            print s_line

test = False
if test:
    for R in range(100):
        print R
        for C in range(R,100):
            for E in range(1, R*C):
                solve(R, C, E)
