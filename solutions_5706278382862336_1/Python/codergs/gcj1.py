#! /opt/local/bin/python
from numpy import *
from itertools import *
import sys
sys.setrecursionlimit(10000)
#from gmpy2 import *
#f=open('test1')
#f=open('A-small-attempt0.in')
f=open('A-large.in')
T=int(f.readline())
def solve(a,b,level):
    #print a,b,level
    if level > 40:
        return -1000000
    if a==0:
        return 0
    if a>=b:
        return min(0,solve(a-b,b,level))
    else:
        val= 1+solve(2*a,b,level+1)
        #print 'val',val
        return val


for tt in range(1,T+1):
    (a,b)=[int(x) for x in f.readline().split('/')]
    ans = solve(a,b,0)
    #print ans
    if ans>0:
        print 'Case','#'+str(tt)+':',ans
    else:
        print 'Case','#'+str(tt)+':','impossible'

