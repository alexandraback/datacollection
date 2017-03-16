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
QNO = 'a' #SET QUESTION NUMBER
FIN,FOUT = QNO+'.in.txt',QNO+'.out.txt'
FIN = QNO.capitalize()+'-small-attempt0.in'
#FIN = QNO.capitalize()+'-large.in'
fin = open(FIN)
fout = open(FOUT,'w')
sys.stdin = fin
######################## PROGRAM  START ##########################

def solve(a):
    return t

for t in range(int(input())):
    s = input()
    l = [s[0]]
    for a in s[1:]:
        if ord(l[0])>ord(a):
            l.append(a)
        else:
            l.insert(0,a)
    print("Case #{0}: {1}".format(t+1,"".join(l)),file=fout)

######################## PROGRAM END #############################
fin.close()
fout.close()
print("Program complete")
