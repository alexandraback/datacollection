#!/usr/bin/python3

import sys

def getNum():
    return int(sys.stdin.readline())

def aDone(a):
    response = True
    for i in range(10):
        if a[i] == 0:
            response = False
            break
    return response

def setA(a,num):
    for i in map(int, str(num)):
        a[i] = 1

t=getNum()
for i in range(1,t+1):
    n=getNum()
    print("Case #" + str(i) + ": ",end="")
    if n == 0:
        print("INSOMNIA")
    else:
        a = [0,0,0,0,0,0,0,0,0,0]
        ninc = n
        while True:
            setA(a,n)
            if aDone(a):
                print(n)
                break
            else:
                n = n + ninc
