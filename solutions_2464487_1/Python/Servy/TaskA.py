'''
Created on 27.04.2013

@author: Servy
'''
import sys
import math

def neededFor(r, k):
    return ((2*r + 1) + (2*(r+2*(k-1)) + 1)) * k // 2;

def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

def solve(r, t):
    d = ((2*r-1) ** 2) + 4 * 2 * t    
    k = (-2*r + 1 + math.floor(isqrt(d))) // 4
    return k

tests = int(sys.stdin.readline())

for test in range(tests):
    (r, t) = map(int, sys.stdin.readline().split())
    print("Case #%d: %d" % (test+1, solve(r, t)))
    
    
    
    
    