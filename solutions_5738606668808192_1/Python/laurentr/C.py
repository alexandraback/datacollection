#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import math

numbers = range(2,2**16)
for i in range(2,2**8+1):
    primes_so_far = []
    for n in numbers:
        if n == i or n % i != 0:
            primes_so_far.append(n)
    numbers = primes_so_far

def divider(a):
    x = 2
    #while x < math.ceil(math.sqrt(a)):
    #    if a % x == 0:
    #        return x
    #    x += 1

    #try only the first prime numbers as possible dividers
    for x in numbers:
        if a % x == 0:
            return x
    return None
 
N = 32
J = 500

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
