from math import sqrt

from decimal import *
getcontext().prec = 100
f= open("input.txt")
c=int(f.readline())
def d(r,t):
	v=0
	return (sqrt(4*r**2+16*r*v-4*r+8*t+16*v**2-8*v+1)-2*r-3)/4
def d2(r,t):
	r=Decimal(r)
	t=Decimal(t)
	return (Decimal(sqrt(4*r**2-4*r+8*t+Decimal(1)))-2*r-Decimal(3))/Decimal(4)
for l in range(c):
	v=f.readline().split()
	r=int(v[0])
	t=int(v[1])
	top = d2(r,t)+1
	print ("Case #"+str(l+1)+": "+str(int(top)))










