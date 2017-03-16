#! /usr/bin/python
import os
import pyximport

#pyximport.install()
#os.chdir(os.path.dirname(os.path.abspath(__file__)))


#from ExtSolve import *

inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

def Solve(*args):
    R, C, W = args
    if R > 1:
        return (C/W) * (R-1) + Solve(1, C, W)
    elif C > 2 * W:
        return 1 + Solve(R, C - W, W)
    else:
        return min(C,W+1)

T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    r, c, w = [int(x) for x in inp.pop(0).split(' ')]
    outf.write('Case #%d: %s\n'%(i+1,Solve(r,c,w)))
outf.close()