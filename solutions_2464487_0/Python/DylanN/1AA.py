#benoni.boy
#Google Code Jam
#13 April 2013
import sys
from math import *
from gmpy import *

sys.stdin = open('C:\GCJ\in.txt')
sys.stdout = open('C:\GCJ\out.txt', 'w')

T = eval(input())
for i in range(T):
    r, t = list(map(int, input().split()))
    print('Case #' + str(i + 1) + ':', (1 - 2*r + sqrt(4*r * (r - 1) + 1 + 8*t))//4)
        

sys.stdin.close()
sys.stdout.close()
