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
QNO = 'b' #SET QUESTION NUMBER
FIN,FOUT = QNO+'.in.txt',QNO+'.out.txt'
FIN = QNO.capitalize()+'-small-attempt0.in'
FIN = QNO.capitalize()+'-large.in'
fin = open(FIN)
fout = open(FOUT,'w')
sys.stdin = fin
######################## PROGRAM  START ##########################

def solve(a):
    return t

for t in range(int(input())):
    X = [0 for i in range(2501)]
    n = int(input());
    for i in range(2*n-1):
        for x in input().strip().split(" "):
            X[int(x)]+=1
    print("Case #{0}:".format(t+1),end=" ",file=fout)
    for x in range(2501):
        if X[x]!=0 and X[x]%2!=0:
            print(x,end=" ",file=fout)
    print("",file=fout)
######################## PROGRAM END #############################
fin.close()
fout.close()
print("Program complete")
