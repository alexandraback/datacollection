import sys
import math
from fractions import Fraction
sys.stdin = open("A-large.in", "r")

def ispower(n, base): 

    if n == base:
        return True

    if base == 1:
        return False

    temp = base

    while (temp <= n):
        if temp == n:
            return True
        temp *= base

    return False

def solve():
    a,b = map(int, sys.stdin.readline().strip().split("/"))
    f = Fraction(a,b)
    if ispower(f.denominator, 2):
    	res = 0
    	n = f.numerator
    	sb = Fraction(1, 2)

    	while f>0:
    		res += 1
    		if f >= sb:
    			return str(res)
    		else:
    			sb *= Fraction(1, 2)
    	print f
    	return str(res)
    else:
    	return "impossible"
T = int(input())
for _t in xrange(T): 
    print "Case #" +str(_t+1) + ": " + solve()