#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import math

def divider(a):
    for x in range(2, int(math.ceil(math.sqrt(a)))):
        if a % x == 0:
            return x
    return None
 
N = 16
J = 50

print "Case #1:"
j = 0
coin = 0
while j < J:
    string = bin(coin)[2:]
    jamcoin = '1'+''.join(['0' for i in range(N-len(string)-2)])+string+'1'
    res = [-1 for i in range(9)]
    for base in range(2,11):
        d = divider(int(jamcoin, base))
        if d == None:
            break
        res[base-2] = d
    if -1 not in res:
        print jamcoin+' '+' '.join([str(r) for r in res])
        j += 1
    coin += 1
