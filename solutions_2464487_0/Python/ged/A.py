#!/usr/bin/python
import sys
import math

def solve(a,b,c):
	return (-b + math.sqrt(b**2 - 4*a*c)) / (2 * a)


def R(r): # i=inner radius
	return math.pi*(2*r + 1)
def Rpi(r): # i=inner radius
#	print "inner r ",r
	return (2*r+1)
def S(r,n): # r given; n rings
	return sum([R(r+2*i) for i in range(n)])
def Spi(r,n): # r given; n rings
	return sum([Rpi(r+2*i) for i in range(n)])
def S3(r,n):
	return 2*n*r + 2*((n**2)) - n

#r = 1
#for i in range(1,10):
	#print i,"ring now takes",R(i)," or ",R(i)/math.pi,"ml total ",S(r,i)
	#print i,"ring now takes",Rpi(i)," or ",Rpi(i),"ml total ",Spi(r,i)
	#print i,"rings takes",2*i*r+2*(i**2)-i
#raise Exception("ok")

inp = [l.strip() for l in sys.stdin]
T = int(inp[0])
l = 1
for t in range(T):
	arr = inp[l].split(" ")
	l += 1

	R = int(arr[0])
	T = int(arr[1])

	root = solve(2, 2*R-1, -T)
	sol = int(math.floor(root))
	sol += 1
	while S3(R,sol)>T:
		sol -= 1
#	print "root 2",sol

  #print "done ",rings," rings; left ",paint


	print "Case #%d: %d" % (t+1, sol)

