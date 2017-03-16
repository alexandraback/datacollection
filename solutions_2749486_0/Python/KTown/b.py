from math import *
tests = input()

for t in range(1,tests+1):
    line = raw_input().split()
    x = int(line[0])
    y = int(line[1])
    tot = abs(x)+abs(y)
    guess = int(sqrt(tot))
    n = guess
    below = 0
    above = 0
    below = n*(n+1)/2
    n = n+1
    while(True):
        if(below >= tot-n):
            break
        below = n*(n+1)/2
        n = n + 1
    above = n*(n+1)/2
    if(tot == 1):
        below=0
        above = 1
        n=1
    if(tot - below) <= (above - tot):
        useBelow = True
    else:
        useBelow = False
    if(useBelow):
        n=n-1
    else:
        pass
    moves = range(n)
    currentPos = [0,0]
    nX = abs(x)
    nY = abs(y)
    for i in range(n):
        if(nX - currentPos[0] >= (n-i)):
            moves[n - i - 1] = 'E'
            currentPos[0] = currentPos[0] + (n - i)
        else:
            moves[n - i - 1] = 'N'
            currentPos[1] = currentPos[1] + (n - i)
    if(useBelow):
        if(nX - currentPos[0] > 0):
            for i in range(nX - currentPos[0]):
                moves.append('W')
                moves.append('E')
        if(nY - currentPos[1] > 0):
            for i in range(nY - currentPos[1]):
                moves.append('S')
                moves.append('N')
    else:
        if(nY - currentPos[1] < 0):
            for i in range(-(nY - currentPos[1])):
                moves.append('N')
                moves.append('S')
    if(x < 0):
        for i in range(len(moves)):
            if moves[i] == 'E':
                moves[i] = 'W'
            elif moves[i] == 'W':
                moves[i] = 'E'
    if(y < 0):
        for i in range(len(moves)):
            if moves[i] == 'N':
                moves[i] = 'S'
            elif moves[i] == 'S':
                moves[i] = 'N'
    currPos = [0,0]
    for i in range(len(moves)):
        if moves[i] == 'N':
            currPos[1] = currPos[1] + i+1
        if moves[i] == 'S':
            currPos[1] = currPos[1] - (i+1)
        if moves[i] == 'E':
            currPos[0] = currPos[0] + i+1
        if moves[i] == 'W':
            currPos[0] = currPos[0] - (i+1)
    if((x - currPos[0]) == 0 and (y - currPos[1]) == 0):
        pass
    else:
        print "FAIL"
    print "Case #" + repr(t) + ": " + ''.join(moves)

