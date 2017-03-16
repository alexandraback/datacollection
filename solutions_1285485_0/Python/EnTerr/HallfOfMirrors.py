#
# Google Code Jam 2012
# Round 0: D. Hall of Mirrors
# submission by EnTerr
#

'''
Limits: T in [1,100], H, W in [3,30], D in [1,50]
All characters in each map will be '#', '.', or 'X'.
Exactly one character in each map will be 'X'. The first row, the last row,
the first column and the last column of each map will be entirely filled
with '#' characters.
Small dataset: There will be no more than 2W+2H-4 '#' characters.
Large dataset: The restriction from the Small dataset does not apply.

Sample Input: 
6
3 3 1
###
#X#
###
3 3 2
###
#X#
###
4 3 8
###
#X#
#.#
###
7 7 4
#######
#.....#
#.....#
#..X..#
#....##
#.....#
#######
5 6 3
######
#..X.#
#.#..#
#...##
######
5 6 10
######
#..X.#
#.#..#
#...##
######

Output:
Case #1: 4
Case #2: 8
Case #3: 68
Case #4: 0
Case #5: 2
Case #6: 28

'''

#import psyco
#psyco.full()

import sys
from time import clock

inf = open(sys.argv[1])
def input(): return inf.readline().strip()


def gcd(a, b):
    while b != 0:
       a, b = b, a % b
    return abs(a)

def areCoprime(a,b):
    return gcd(abs(a),abs(b)) <= 1

def countReflections(W,H,D,x,y):
    #print W,H,D,x,y
    dd = D**2
    cnt = {}
    for i in range(-6*D/H, 6*D/H+1):
        for j in range(-6*D/W, 6*D/W+1):
            if i or j:
                xx = 2*((j+1)/2)*W + (-1)**(j%2)*x
                yy = 2*((i+1)/2)*H + (-1)**(i%2)*y
                dx = xx - x
                dy = yy - y
                if dx**2 + dy**2 <= dd:
                    #print i,j, xx,yy
                    cnt[dx / gcd(dx,dy), dy / gcd(dx,dy)] = True
    return len(cnt)

for caseNo in range(1, int(input())+1):
    print 'Case #%d:' % caseNo,
    #tm = clock()
    H,W,D = map(int, input().split())
    board = ''.join(input() for _ in range(H))
    Xpos = board.index('X')
    x, y = Xpos % W, Xpos / W
    # double the values to eliminate 0.5 coords of X, deal only with ints
    print countReflections(2*(W-2), 2*(H-2), 2*D, 2*x-1, 2*y-1)
    #print >>sys.stderr, caseNo, clock() - tm
    
