#!/usr/bin/python3
from sys import stdin

cases = int(stdin.readline())

for t in range(1,cases+1):
    line = stdin.readline().strip()
    [x, r, c] = line.split(' ', 2)
    x = int(x)
    r = int(r)
    c = int(c)
    a = max(r,c)
    b = min(r,c) ## a > b
    winner = 'GABRIEL'
    if (((a*b) % x) != 0):
        winner = 'RICHARD'
    else:
        if (a < x):
            winner = 'RICHARD'
        elif (x > 2*b): # outside the grid
            winner = 'RICHARD'
        elif (a > 3) and (b > 1): # "diagonial steps" in non square
            if ((b*a)/x == 2): # assymetric
                winner = 'RICHARD'
        if ((a > 2) and (a > 2) and (x > 7)): # the hole
                winner = 'RICHARD'
    
    print (('Case #%d: %s' % (t,winner)))
        
