#!/usr/bin/python2.7

import sys
import math

def jamcoin_to_str(jamcoin):
    ret = ""
    for i in xrange(len(jamcoin)-1, -1, -1):
        ret += "%d" % (jamcoin[i])
    return ret

T = int(sys.stdin.readline())

for i in xrange(T):
    line  = sys.stdin.readline()
    words = line.strip().split()
    N     = int(words[0])
    J     = int(words[1])

    half_N = N >> 1

    print "Case #{0}: ".format((i+1))
    
    n     = 1
    for j in xrange(J):
        tmp = n
        jamcoin_half = [0] * half_N
        jamcoin_half[-1] = 1
        divisors     = [0] * 9
        for k in xrange(0, half_N - 1):
            jamcoin_half[k] = (tmp % 2)
            tmp /= 2
        for base in xrange(2, 11):
            s = 1
            for k in xrange(0, half_N):
                divisors[base-2] += s * jamcoin_half[k]
                s *= base
        half_str = jamcoin_to_str(jamcoin_half)
        print half_str + half_str,
        for base in xrange(2, 11):
            print divisors[base-2],
        print
        n += 2
