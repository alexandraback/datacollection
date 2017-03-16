# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys
import math

# <codecell>

def divisor(n):
    #returns the smallest divisor for n greater than 1
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3
    
    d = 5
    w = 2
    while d*d <= n:
        if n % d == 0:
            return d
        d += w
        w = 6 - w
    
    return 0
        
    
def is_coin_jam(s):
    """given a number given as a binary string, determine if it is a composite number in all bases from 2 to 10"""
    l = []
    for base in range(2,11):
        n = divisor(int(s,base))
        if n > 0:
            l.append(n)
        else:
            return []
    return l

target = 50
found = 0
number = 0
print "Case #1:"
while found < target:
    s = "1{0:014b}1".format(number)
    l = is_coin_jam(s)
    if l:
	for x in l:
		s += " {0}".format(x)
        print s
        found += 1
    number += 1
    

# <codecell>


