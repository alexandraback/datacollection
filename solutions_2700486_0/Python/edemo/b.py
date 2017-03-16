#!/usr/bin/python3.2
name = 'b.test'
from math import sqrt
name = 'B-small-attempt1.in'
#name = 'B-large.in'

cache = {0:1, 1:1, 2:2, 3:6}
def factorial(x):
    if x not in cache:
        cache[x] = x*factorial(x-1)
    return cache[x]

def nCk(n,k):
    return factorial(n)/(factorial(k)*factorial(n-k))



#print(nCk(10,1), nCk(10,0))

def score(core, leftover, height):
    if leftover >= core + 1 + height + 1: return 1.0
    if leftover < height: return 0.0
    if leftover > core + 1:
        forSure = leftover - (core + 1)
        return 1 - .5**((leftover - 2*forSure) - (height-forSure))



    if leftover <= core + 1:
        p = 0
        for i in range(0,core+1):
            j = leftover - i
            if j >= height + 1:
                p += (.5**j)*(.5**i) * nCk(leftover,j)
        return p

        


def f(x,n):
    return x*x + x -(2*n)

def getCore(N):
    if N == 1: return (1,0)
    close = (-1 + sqrt(1 + 8*N))//2
    close -= 2
    while close*close + close - 2*N <= 0:
        close += 1
    close -= 1
    if close % 2 == 0: close -= 1
    close = int(close)
    leftover = N - (close*close + close)//2
    return close,leftover


def make():
    N,X,Y = [int(i) for i in FILE.readline().split()]
    if N == 0: return 0.0
    if N == 1 and (X != 0 or Y != 0): return 0.0
    if X == 0 and Y == 0: return 1.0
    #if abs(X)+abs(Y) > 2*(N-1): return 0.0
    if (X % 2 == 1) and (Y % 2 == 0): return 0.0
    if (X % 2 == 0) and (Y % 2 == 1): return 0.0

    core,leftover = getCore(N)
    if leftover == 0:
        if abs(X) + abs(Y) > 2*(core-1): return 0.0
        else: return 1.0
    if abs(X) + abs(Y) <= 2*(core-1):
        return 1.0
    if abs(X) + abs(Y) > 2*core: return 0.0

    X = abs(X)
    Y = abs(Y)
    if X == 0: return 0.0

    return score(core, leftover, Y)
    #if leftover <= core + 1:
    #    return 1.0 - .5**(leftover -Y//2)
    #if Y == 1: return (1.0 - ((.5**leftover) + (.5**(leftover-1))))


    return 5













FILE = open(name)
T = int(FILE.readline())

for i in range(1, T+1):
    print("Case #" + str(i) + ": " + str(make()))