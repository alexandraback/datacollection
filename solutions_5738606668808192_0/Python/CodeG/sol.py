#!/usr/bin/python

import math

t = int(raw_input())
nandj = raw_input().split(" ")

n = int(nandj[0])
j = int(nandj[1])

pad = n - 2

def getNextString(num):
    return ('1' + bin(num)[2:].zfill(pad) + '1')

def isPrime(num):
    max_limit = 100
    for x in range(2, max_limit):
        if num % x == 0:
            return x
    return -1

nums = 0
cur_num = 0
max_num = 2 ** pad

print "Case #1:"

while nums < j and cur_num < max_num:
    bin_string = getNextString(cur_num)
    cur_num += 1
    factors = [str(isPrime(int(bin_string, b))) for b in range(2,11)]
    if "-1" not in factors:
        print bin_string, " ".join(factors)
        nums += 1
