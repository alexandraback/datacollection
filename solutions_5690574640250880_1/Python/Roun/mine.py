#!/usr/bin/env python

from __future__ import print_function
from sys import argv,stdin


class MineSolver:
    def __init__(self,R,C,M):
        self.M=M
        self.RC=R*C
        self.E=self.RC-M
        if R > C:
            self.R = C
            self.C = R
            self.transposed = True
        else:
            self.R = R
            self.C = C
            self.transposed = False
        self.board = [['*']*self.C for i in xrange(self.R)]
    def printboard(self):
        self.board[0][0] = 'c'
        if self.transposed:
            for i in xrange(self.C):
                for j in xrange(self.R):
                    print(self.board[j][i],end='')
                print('\n',end='')
        else:
            for i in xrange(self.R):
                for j in xrange(self.C):
                    print(self.board[i][j],end='')
                print('\n',end='')

with open(argv[1]) if len(argv)>1 else stdin as f:
    num_cases = int(f.readline())
    for i in xrange(num_cases):
        print('Case #%d:'%(i+1))
        R, C, M = [int(x) for x in f.readline().split()]
        s = MineSolver(R,C,M)
        if s.M==0:
            s.board=[['.']*s.C for i in xrange(s.R)]
        elif s.R == 1 or s.E == 1:
            for i in xrange(s.E):
                s.board[0][i] = '.'
        elif s.E in [2,3,5,7] or (s.E%2==1 and s.R==2):
            print('Impossible')
            continue
        else:
            quo = s.E/2/s.C
            rem = (s.E/2)%s.C            
            for j in xrange(quo+(1 if rem!=0 else 0)):
                if 2*j==s.R-1 or (j==quo and rem == 1):
                    for k in xrange(s.E/2-j*s.C):
                        s.board[2*j][2*k] = '.'
                        s.board[2*j][2*k+1] = '.'
                else:
                    for k in xrange(min(s.E/2-j*s.C,s.C)):
                        s.board[2*j][k] = '.'
                        s.board[2*j+1][k] = '.'
                
            if s.E%2 == 1:
                if rem==0:
                    s.board[2*quo-1][s.C-1] = '*'
                    s.board[2*quo-2][s.C-1] = '*'
                    s.board[2*quo][0]='.'
                    s.board[2*quo][1]='.'
                    s.board[2*quo][2]='.'
                elif rem == 1:
                    s.board[2*quo][rem+1] = '.'
                elif j==0:
                    s.board[2*j][k] = '*'
                    s.board[2*j+1][k] = '*'
                    s.board[2*j+2][0] ='.'
                    s.board[2*j+2][1] ='.'
                    s.board[2*j+2][2] ='.'
                else:
                    s.board[2*quo][rem] = '.'
                
        s.printboard()
