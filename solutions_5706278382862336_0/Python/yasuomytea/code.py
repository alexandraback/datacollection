from fractions import gcd
from math import log
import sys
    
filename = sys.argv[1]
outputfile = "gcdresult"

fi = open(filename, 'r')
fo = open(outputfile, 'w')

def bLog2(a):
    return a & (a-1)

def iLog2(a):
    return int(log(a) / log(2))

caseNum = int(fi.readline())
for i in range(caseNum):
    [P, Q] = [int(item) for item in fi.readline().split('/')]
    g = gcd(P, Q)
    P1 = P / g
    Q1 = Q / g
    
    if P1 == 0 or bLog2(Q1):
        fo.write( 'Case #{0}: impossible\r\n'.format(i+1))
    else:
        fo.write( 'Case #{0}: {1}\r\n'.format(i+1, iLog2(Q1) - iLog2(P1)))
