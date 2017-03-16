from math import *
from fractions import *
c=input().strip()
for x in range(int(c)):
	a,b=input().strip().split('/')
	a,b=int(a), int(b)
	f=Fraction(a,b)
	if(floor(log2(f.denominator))!=ceil(log2(f.denominator))):
		print('Case #', x+1, ': ', 'impossible', sep='')
	else:
		a=2**floor(log2(f.numerator))
		q=Fraction(a,f.denominator)
		#print (f,a,q)
		print('Case #', x+1, ': ', ceil(log2(q.denominator)), sep='')
