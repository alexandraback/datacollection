'''
Created on Apr 26, 2013

@author: hwy
'''

import math

def isqrt(n):
    xn = 1  
    xn1 = (xn + n / xn) / 2  
    while abs(xn1 - xn) > 1:  
        xn = xn1  
        xn1 = (xn + n / xn) / 2  
    while xn1 * xn1 > n:  
        xn1 -= 1  
    return xn1

def init():
    w = open('ou.txt', 'w')
    f = open('A-large.in', 'r')
    num = int(f.readline())
    
    for i in range(1, num + 1):
        w.write('Case #' + str(i) + ': ')
        [r, t] = [long(s) for s in f.readline().split()]
        b = (2 * r - 1) * (2 * r - 1) + 8 * t 
        out = long((1 - 2 * r + isqrt(b)) / 4.0)
        w.write(str(out) + '\n')
        
if __name__ == '__main__':
    init()
