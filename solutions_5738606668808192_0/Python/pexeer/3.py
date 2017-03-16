#!/usr/bin/env python3

import math
import random


def diver(n):
    r = int(math.floor(math.sqrt(n)))
    for i in range(2, r+1):
        if n % i == 0:
            return i
    return 1


def try_one(ret):
    #slen=32
    #i2 = random.randint(0, 2**30) + 2**31 + 1
    slen=16
    i2 = random.randint(0, 2**14 - 1) * 2 + 2**15 + 1
    #len=6
    #i2 = random.randint(0, 2**4 - 1) * 2 + 2**5 + 1
    s= "{0:b}".format(i2)
    for base in range(2, 11):
        i = int(s, base);
        ii = diver(i)
        if ii == 1:
            return 0
        else:
            ret[base] = ii

    return i2

if __name__ == '__main__':
    ret = [0,0,0,0,0,0,0,0,0,0,0,0,0]
    for x in range(0, 1000):
        x = try_one(ret)
        if x != 0:
            s= "{0:b}".format(x)
            print(s, ret[2], ret[3], ret[4], ret[5],
                    ret[6], ret[7], ret[8], ret[9], ret[10])
