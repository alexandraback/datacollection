import sys
from math import sqrt
sys.stdin = open('in.in')
sys.stdout = open('out.out', 'w')
T = input()

def sol():
    r, t = map(long, raw_input().split())
    return long((sqrt(1.*(4*r*r-4*r+1+8*t))-2*r+1)/4)



for ca in range(1, T+1):
    res = sol()
    print 'Case #'+str(ca)+':', res
