'''
Created on 04.05.2013

@author: Servy
'''
import sys
import operator
from functools import reduce

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

def getFullLevels(n):
    d = isqrt(1 + 8 * n)
    res = (1 + d) // 4
    return (res, n - res*(2*res - 1))

def c(n, k):
    return (reduce(operator.mul, range(n-k+1, n+1), 1) //
            reduce(operator.mul, range(1, k+1), 1))

def calcProb(y, n):
    cnks = 0
    for k in range(y+1, n+1):
        cnks += c(n, k)
    count = n
    while ((cnks % 2 == 0) and (count > 0)):
        cnks = cnks // 2
        count -= 1
    return cnks / (2 ** count)

def solve(n, x, y):
    x = abs(x)
    if (x + y) % 2 == 1:
        return 0.0
    
    (levels, leftover) = getFullLevels(n)
    level = ((x + y) // 2) + 1
    if level <= levels:
        return 1.0
    if level > levels + 1:
        return 0.0
    if x == 0:
        return 0.0
    return calcProb(y, leftover)

tests = int(sys.stdin.readline())

for t in range(tests):
    (n, x, y) = map(int, sys.stdin.readline().split())    
    print("Case #%d: %.6f" % (t+1, solve(n, x, y)))