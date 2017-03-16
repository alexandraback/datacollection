import os
import sys

T = int(sys.stdin.readline())

def is_palindrom(s):
	return s == s[::-1]

assert is_palindrom("12321")
assert not is_palindrom("012321")

def isqrt(n):  
    xn = 1  
    xn1 = (xn + n/xn)/2  
    while abs(xn1 - xn) > 1:  
        xn = xn1  
        xn1 = (xn + n/xn)/2  
    while xn1*xn1 > n:  
        xn1 -= 1  
    return xn1 

for t in range(T):
	line = sys.stdin.readline()
	(A,B) = [ int(x) for x in line.split() ]
	rA = isqrt(A) - 1
	rB = isqrt(B) + 1

	result = 0
	for n in xrange(rA,rB):
		n_str = str(n)
		if is_palindrom(n_str):
			n2 = n*n
			if n2 >= A and n2 <=B:
				n2_str = str(n2)
				if is_palindrom(n2_str):
					result += 1

	print "Case #%d: %d" % (t+1, result)

    
