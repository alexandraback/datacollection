#!/usr/bin/python
# -*- coding: UTF-8 -*-
"""
Area[r] = (r+1)² - r² 
        = r² + 2r + 1 - r²
        = 2r + 1

Area[r0, n] = Sum(Area(r0+2*i))
            = Sum(2r0 + 4i + 1)
            = (2r0 + 1).N + 4*Sum(i)
            = (2r0 + 1).N + 4*N*(N-1)/2
            = (2r0 + 1).N + 2*N*(N-1)
            = (2r0 + 1).N + 2*N² - 2N
            = 2.N² + (2r0 - 1).N

N = 
"""
import math
def area1(r0, N):
    ret = 0
    for i in range(int(N)):
	a = r0+2*i
	b = r0+2*i+1
	A = b*b - a*a
	ret += A
	
    return ret

def calcN(r0, A):
    a = 2
    b = 2*r0 - 1
    c = -A
    ret = (-b + math.sqrt(b*b - 4*a*c)) / (2*a)
    #return int(math.floor(ret))
    return ret

def calcArea(r0, N):
    return 2*N*N + (2*r0 - 1)*N

def funfa(r0, A):
    N = int(calcN(r0, A)) - 2
    while calcArea(r0, N) <= A:
        N+= 1
    return N - 1


def readLine():
    return tuple(map(int, raw_input().split(' ')))

(n_tests,) = readLine()
for test in range(1, n_tests+1):
    r0, A = readLine()
    print('Case #%d: %d' % (test, funfa(r0, A)))
