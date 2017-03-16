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
FIN,FOUT = QNO+'.in.txt',QNO+'.out.2.txt'
FIN = QNO.capitalize()+'-small-attempt1.in'
#FIN = QNO+'.sample.txt'
#FIN = QNO.capitalize()+'-large.in'
fin = open(FIN)
fout = open(FOUT,'w')
sys.stdin = fin
######################## PROGRAM  START ##########################

def solve(a,n):
    return len(a)

for t in range(int(input())):
    (J,P,S,K) = [int(i) for i in input().strip().split(" ")]
    valid = []
    jp = {}
    js = {}
    ps = {}
    for j in range(1,J+1):
        for p in range(1,P+1):
            jp[(j,p)] = 0
    for j in range(1,J+1):
        for s in range(1,S+1):
            js[(j,s)] = 0
    for p in range(1,P+1):
        for s in range(1,S+1):
            ps[(p,s)] = 0
    for j in range(1,2):
        for p in range(1,P+1):
            for s in range(1,S+1):
                if jp[(j,p)]<K and js[(j,s)]<K and ps[(p,s)]<K:
                    valid.append((j,p,s))
                    jp[(j,p)]+=1
                    js[(j,s)]+=1
                    ps[(p,s)]+=1
    print("Case #{0}: {1}".format(t+1,len(valid)*min(J,K)),file=fout)
    for j in range(min(J,K)):
        for i in valid:
            print("{0} {1} {2}".format(i[0]+j,(i[1]+j)%P,(i[2]+j)%S),file=fout)
######################## PROGRAM END #############################
fin.close()
fout.close()
print("Program complete")
