from math import sqrt

def numreverse(num):
	return int(str(num)[::-1])

def ispalindrome(num):
	if numreverse(num)==num:
		return True
	return False

inp = open("file1.txt").read().splitlines()
outp = open("out1.txt","w")

vec = []

for i in range(1,10000001):
	if ispalindrome(i) and ispalindrome(i**2):
		vec.append(i**2)

for i in range(1,len(inp)):
	foo = list(map(int,inp[i].split()))
	c = 0
	for j in vec:
		if j > int(foo[1]):
			break
		elif j >= int(foo[0]) and j <= int(foo[1]):
			c += 1
	outp.write("Case #"+str(i)+": "+str(c)+"\n")
