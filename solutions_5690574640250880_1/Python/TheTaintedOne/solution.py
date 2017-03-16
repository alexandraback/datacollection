import sys
import itertools

lines = sys.stdin.readlines()

ntests = int(lines[0])

curr = 1
for t in range(1, ntests+1):
    R0, C0, M0 = [int(x) for x in lines[curr].split()]
    R, C, M = R0, C0, M0

    mines = [x[:] for x in [["."]*C]*R]
    
    # add click
    N0 = (R*C)-M
    N = N0

    # fill mines in safe region
    for r in reversed(range(2, R)):
        for c in reversed(range(2, C)):
            if M>0:
                mines[r][c] = '*'
                M -= 1

    offset = 2
    if M%2 > 0 and R>=3 and C>=3:
        mines[offset][offset] = '.'
        offset = 3
        M += 1


    possible = True
    if R>1 and C>1:
        possible = M%2==0
        

    for r in reversed(range(offset, R)):
        for c in reversed(range(0, min(2,C))):
            if M>0:
                mines[r][c] = '*'
                M -= 1

    for c in reversed(range(offset, C)):
        for r in reversed(range(0, min(2,R))):
            if M>0:
                mines[r][c] = '*'
                M -= 1


    # print M


    possible = (possible and (M==0)) or (M0+1)==(R*C)
    # click
    mines[0][0] = 'c'
    for r in reversed(range(0, min(offset,R))):
        for c in reversed(range(0, min(offset,C))):
            if M>0:
                mines[r][c] = '#'
                M -= 1


    if possible:
        for r in range(0, R):
            for c in range(0, C):
                if mines[r][c]=='#':
                    mines[r][c] = '*'

        
    # print t, "   ", R0,C0,"   ",M0, "   ",possible
    # for r in mines:
    #     print "".join(r)
    # print

    curr += 1


    if possible:
        print "Case #"+ str(t) + ":"
        for r in range(0, R):
            print "".join(mines[r])
    else:
        print "Case #"+ str(t) + ":"
        print "Impossible"
