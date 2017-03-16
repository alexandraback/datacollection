'''
Problem C. Minesweeper Master

Small input
11 points

Large input
24 points

Problem

Minesweeper is a computer game that became popular in the 1980s, and
is still included in some versions of the Microsoft Windows operating
system. This problem has a similar idea, but it does not assume you
have played Minesweeper.

In this problem, you are playing a game on a grid of identical cells.
The content of each cell is initially hidden. There are M mines hidden
in M different cells of the grid. No other cells contain mines. You
may click on any cell to reveal it. If the revealed cell contains a
mine, then the game is over, and you lose. Otherwise, the revealed
cell will contain a digit between 0 and 8, inclusive, which
corresponds to the number of neighboring cells that contain mines. Two
cells are neighbors if they share a corner or an edge. Additionally,
if the revealed cell contains a 0, then all of the neighbors of the
revealed cell are automatically revealed as well, recursively. When
all the cells that don't contain mines have been revealed, the game
ends, and you win.

For example, an initial configuration of the board may look like this
('*' denotes a mine, and 'c' is the first clicked cell):

*..*...**.
....*.....
..c..*....
........*.
..........

There are no mines adjacent to the clicked cell, so when it is
revealed, it becomes a 0, and its 8 adjacent cells are revealed as
well. This process continues, resulting in the following board:

*..*...**.
1112*.....
00012*....
00001111*.
00000001..

At this point, there are still un-revealed cells that do not contain
mines (denoted by '.' characters), so the player has to click again in
order to continue the game.

You want to win the game as quickly as possible. There is nothing
quicker than winning in one click. Given the size of the board (R x C)
and the number of hidden mines M, is it possible (however unlikely) to
win in one click? You may choose where you click. If it is possible,
then print any valid mine configuration and the coordinates of your
click, following the specifications in the Output section. Otherwise,
print "Impossible".

Input

The first line of the input gives the number of test cases, T. T lines
follow. Each line contains three space-separated integers: R, C, and M.

Output

For each test case, output a line containing "Case #x:", where x is
the test case number (starting from 1). On the following R lines,
output the board configuration with C characters per line, using '.'
to represent an empty cell, '*' to represent a cell that contains a
mine, and 'c' to represent the clicked cell.

If there is no possible configuration, then instead of the grid,
output a line with "Impossible" instead. If there are multiple
possible configurations, output any one of them.

Limits

0 <= M < R * C.
Small dataset

1 <= T <= 230.
1 <= R, C <= 5.
Large dataset

1 <= T <= 140.
1 <= R, C <= 50.

Sample

Input

5
5 5 23
3 1 1
2 2 1
4 7 3
10 10 82

Output

Case #1:
Impossible
Case #2:
c
.
*
Case #3:
Impossible
Case #4:
......*
.c....*
.......
..*....
Case #5:
**********
**********
**********
****....**
***.....**
***.c...**
***....***
**********
**********
**********
'''

from collections import deque
#from decimal import Decimal
from sys import stdin, stderr
import copy
import fractions
import heapq
import itertools
import math
#import networkx as nx
import random
import re
import sys

sys.setrecursionlimit(100)

isa = isinstance
INF = 1 << 66

DX = (0,1,1,1,0,-1,-1,-1)
DY = (-1,-1,0,1,1,1,0,-1)
def is_win(B):
    R = len(B); C = len(B[0])
    for i in range(R):
        for j in range(C):
            if B[i][j] == '.':
                return False
    return True
def is_possible(ci,cj,B,dp):
    if (ci,cj) in dp:
        return dp[ci,cj]
    R = len(B); C = len(B[0])
    if B[ci][cj] == '*':
        return False
    B[ci][cj] = 'c'
    if is_win(B):
        return True
    zero = True
    adj = list()
    for dx in DX:
        for dy in DY:
            x = ci+dx; y = cj+dy
            if 0 <= x < R and 0 <= y < C:
                if B[x][y] == '*':
                    zero = False
                    break
                if B[x][y] != 'c':
                    adj.append((x,y))
    if zero is False:
        B[ci][cj] = '.'
        dp[ci,cj] = False
        return False
    for x,y in adj:
        B[x][y] = 'E'
    if is_win(B):
        return True
    for x,y in adj:
        if is_possible(x,y,B,dp):
            return True
    for x,y in adj:
        B[x][y] = '.'
    B[ci][cj] = '.'
    dp[ci,cj] = False
    return False
def make_string(ci,cj,B):
    R = len(B); C = len(B[0])
    S = list()
    for i in range(R):
        L = list()
        for j in range(C):
            c = B[i][j]
            if c != '*' and (i,j) != (ci,cj):
                c = '.'
            L.append(c)
        S.append("".join(L))
    return S
def solve(R,C,M):
    for mine in itertools.combinations(range(R*C),M):
        B = [ ['.']*C for _ in range(R) ]
        for i in range(R):
            for j in range(C):
                if i*C+j in mine:
                    B[i][j] = '*'
        dp = dict()
        for i in range(R):
            for j in range(C):                
                if is_possible(i,j,B,dp):
                    return make_string(i,j,B)
    return ['Impossible']

def check_test(A, B, data='', case=[0]):
    print
    print "test %d:" % case[0]
    print A
#   if abs(A-B) > 1e-9:
    if A != B:
        if data:
            print data
        print '>>>', A
        print '<<<', B
        print "!!!!!!!! FAIL !!!!!!!!"
    else:
        print ":::::::) OK"
    case[0] += 1

def unit_test():
    print
    R,C,M = (4,2,5)
    ans = solve(R,C,M)
    for s in ans:
        print s

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        R,C,M = [int(i) for i in stdin.next().split()]
        # print >>stderr, '--', case
        # if case in [12]:
        #     print >>stderr, A
        #     break
        print >>stderr, '--', R,C,M
        ans = solve(R,C,M)            
        print 'Case #%d:' % case
        for s in ans:
            print s

if __name__ == '__main__':
#    unit_test()
    output()
