from math import sqrt

def numreverse(num):
	s = str(num)
	out = ''
	for i in range(0,len(s)):
		out += s[-1]
		s = s[:-1]
	return int(out)

def ispalindrome(num):
	if numreverse(num)==num:
		return 1
	return 0

inp = open("file1.txt").read().splitlines()
outp = open("out1.txt","w")

vec = []

for i in range(1,1001):
	s = sqrt(i)
	if s % 1 == 0 and ispalindrome(i):
		if ispalindrome(int(s)):
			vec.append(i)

for j in range(1,len(inp)):
	c = 0
	test = inp[j].split()
	for k in range(0,len(vec)):
		if vec[k] >= int(test[0]) and vec[k] <= int(test[1]):
			c += 1
	outp.write("Case #"+str(j)+": "+str(c)+"\n")

#for j in range(1,len(inp)):
#	test = inp.split()
#	if test[0] > vec[-1] or test[1] < vec[0]:
#		c = 0
#	else:
#		cd1 = False
#		cd2 = False
#		if test[1] > vec[-1]:
#			b = len(inp)
#			cd1 = True
#		if test[0] < vec[0]:
#			a = 0
#			cd2 = True
#		if not cd2:
#			a = next(x[0] for x in enumerate(vec) if x[1] >= int(test[0]))
#		if not cd1:
#			b = next(x[0] for x in enumerate(vec) if x[1] > int(test[1]))
#		c = b-a
	

