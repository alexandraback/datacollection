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

    pN = int(sys.stdin.readline())
    l = sys.stdin.readline().strip().split(" ")
    diners = sorted(map(int,l))

    debug("diners",diners)

    # 一番多い人が時間数
    maxD = diners[-1]
    a = maxD

    for i in range(maxD - 1):
        # 食べる時間
        bunkatsu = maxD - i
        debug("bunkatsu", bunkatsu)
        kaisu = 0
        for d in diners :
            # 食べる時間の数になるように分割する
            k = int(math.ceil(d/bunkatsu)) - 1
            debug("sara",str(d) + "," + str(k))
            kaisu += k
            debug("kaisu",kaisu)

        newA = kaisu + bunkatsu
        if a > newA :
            a = newA

    print("Case #" + str(q) + ": " + str(a))
    pass

for q in range(qNum):
    ans(q+1)
