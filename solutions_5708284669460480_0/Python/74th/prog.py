#!/usr/bin/env python3
# coding: UTF-8

import sys,math

DEBUG = True
DEBUG = False

qNum = int(sys.stdin.readline())
def debug(s1,s2):
    if DEBUG :
        print(str(s1) + ":" + str(s2))

def ans(q):
    a = 0

    l = sys.stdin.readline().strip().split(" ")
    K = int(l[0])
    L = int(l[1])
    S = int(l[2])
    TYPE = sys.stdin.readline().strip()
    TARGET = sys.stdin.readline().strip()

    debug("K",K)
    debug("TARGET",TARGET)

    # 繰り返し判定
    kuri= 0
    for i in range(1,L) :
        debug("i",i)
        debug("1",TARGET[i:])
        debug("2",TARGET[:-1 * i])
        if TARGET[i:] == TARGET[:-1 * i] :
            kuri= i
            break
    debug("kuri",kuri)

    if kuri == 0 :
        maxBa = math.floor( S / L )
    else:
        maxBa = math.floor( (S-L) / kuri ) + 1
    debug("maxBa",maxBa)
    ans = 0

    # 繰り返しの分の確率
    plus = S - L + 1
    keyNum = 0
    bunbo = 1
    bunshi = plus
    for i in range(L):
        bunbo *= K
        keyNum = 0
        for j in range(K):
            if TYPE[j] == TARGET[i] :
                keyNum += 1
        debug("key-" + TARGET[i],keyNum)
        if keyNum == 0:
            print("Case #" + str(q) + ": 0.0")
            return
        bunshi *= keyNum
    plus = bunshi / bunbo
    debug("plus",plus)

    # 繰り返し外の確率
    minus = 0
    if kuri > 0 :
        minus = S - ( L + kuri ) + 1
        keyNum = 0
        bunbo = 1
        bunshi = minus
        for i in range(L):
            bunbo *= K
            keyNum = 0
            for j in range(K):
                if TYPE[j] == TARGET[i] :
                    keyNum += 1
            debug("key-" + TARGET[i],keyNum)
            if keyNum == 0:
                print("Case #" + str(q) + ": 0.0")
                return
            bunshi *= keyNum
        for i in range(kuri):
            bunbo *= K
            keyNum = 0
            for j in range(K):
                if TYPE[j] == TARGET[i] :
                    keyNum += 1
            debug("key-" + TARGET[i],keyNum)
            if keyNum == 0:
                print("Case #" + str(q) + ": 0.0")
                return
            bunshi *= keyNum
        minus = bunshi / bunbo
    debug("minus",minus)

    #needBa = plus - minus
    needBa = plus 

    ans = maxBa - needBa

    print("Case #" + str(q) + ": " + str(ans))
    pass

for q in range(qNum):
    ans(q+1)
