############### Author: Bipul Ranjan @ranjanbipul ###############
import sys
import time
import os
import math
import operator
import random
from functools import lru_cache
from decimal import Decimal as D
from fractions import Fraction as F
#sys.setrecursionlimit(10000)
#@lru_cache(maxsize=None)
MOD = 1000000007
################################################################
QNO = 'c' #SET QUESTION NUMBER
FIN,FOUT = QNO+'.in.txt',QNO+'.out.txt'
FIN = QNO.capitalize()+'-small-attempt1.in'
#FIN = QNO.capitalize()+'-large.in'
fin = open(FIN)
fout = open(FOUT,'w')
sys.stdin = fin
######################## PROGRAM  START ##########################

a = []
b = []
n = 0 
MAX = 0
def makeChain(c,forward):
    global MAX
    #print("{0},{2} : {1}".format(forward,str(c),MAX))
    if forward:
        bff = a[c[-1]]
        if bff not in c:
            c.append(bff)
            if a[bff]==c[-2]:
                if MAX<len(c): MAX = len(c)
                makeChain(c,False)
            else:
                makeChain(c,True)
        elif bff==c[0]:
            if MAX<len(c): MAX = len(c)
    else:
        for i in range(1,n+1):
            if i not in c:                
                if i in b[c[-1]]:
                    d = c[:]
                    d.append(i)
                    makeChain(d,False)
                    if MAX<len(c)+1: MAX = len(c)+1
                else:
                    d = c[:]
                    d.append(i)
                    makeChain(d,True)


for t in range(int(input())):
    n = int(input())
    a = [0]+[int(i) for i in input().strip().split(" ")]
    b = [[] for i in range(n+1)]
    MAX = 0
    for i in range(1,n+1):
        b[a[i]].append(i)
    for i in range(1,n+1):
        makeChain([i],True)
    print("Case #{0}: {1}".format(t+1, MAX),file=fout)
######################## PROGRAM END #############################
fin.close()
fout.close()
print("Program complete")
