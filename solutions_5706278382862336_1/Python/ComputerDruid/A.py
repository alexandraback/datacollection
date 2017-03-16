#!/usr/bin/env python
from fractions import gcd

def num_digits(n):
    count = 0
    while n > 0:
        count += 1
        n >>= 1
    return count

T = int(raw_input())
for t in range(T):
    frac = raw_input().split("/")
    num = int(frac[0])
    den = int(frac[1])
    divisor = gcd(num, den)
    num /= divisor
    den /= divisor
    n_num = num_digits(num)
    d_num = num_digits(den)
    if den != 2**(d_num-1):
        print "Case #%d: impossible"%(t+1)
    else:
        print "Case #%d: %d"%(t+1,d_num - n_num)
