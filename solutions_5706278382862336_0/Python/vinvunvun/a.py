from collections import *

inFile = open("input.txt", "r")

outFile = open("out.txt", "w")

T = int(inFile.readline())

def two(n):
	while(n != 1):
		if n%2 == 1:
			return False
		n/=2
	return True

def simplify(a,b):
	while b%2 == 0:
		b/=2
	if a%b != 0:
		return False
	return True


for t in xrange(T):
	outFile.write("Case #" + str(t+1) + ": ")
	a,b = inFile.readline().split('/')
	a = int(a)
	b = int(b)
	if a > b:
		outFile.write("impossible")
	if not simplify(a,b):
		outFile.write("impossible")
	else:
		cnt = 0
		n = b
		target = a
		while n != target:
			cnt+=1
			buff = target*2 - n
			if buff < 0:
				n = (n+1)/2
			else:
				break
		outFile.write(str(cnt))
	outFile.write("\n")



