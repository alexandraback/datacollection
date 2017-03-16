#!/usr/bin/python3.2
#name = 'A.test'
#name = 'A-small-attempt0.in'
name = 'A-large.in'
from math import sqrt

def quadratic(A,B,C):
    discrim = sqrt(B*B - 4*A*C)
    temp = (-B + discrim)//(2*A)
    while (temp*temp*A) + B*temp + C > 0:
        temp -= .1
    return temp

def make():
    r,t = [int(i) for i in FILE.readline().split(' ')]
    a = 2
    b = (2*r - 1)
    c = -t
    return int(quadratic(a,b,c))













FILE = open(name)
T = int(FILE.readline())

for i in range(1, T+1):
    print("Case #" + str(i)+ ": " + str(make()))