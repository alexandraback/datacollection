import math
import sys
def gcd(a,b):
	x = max(a,b)
	y = min(a,b)
	while y != 0:
		tmp = y
		y = x % y
		x = tmp
	return x
def Solve():
	strings = my_file.readline()
	p = ""
	q = ""
	isp = True
	for i in strings:
		if i == '/':
			isp = False
		elif isp:
			p += i
		else:
			q += i
	p = int(p)
	q = int(q)
	gcdpq = gcd(p,q)
	p = int(p/gcdpq)
	q = int(q/gcdpq)
	logq = 0
	while q % 2 == 0:
		logq += 1
		q = q / 2
	if q != 1:
		return "impossible"
	logp = math.floor(math.log(p,2))
	ans = logq-logp
	return str(ans)

	


def printCase(caseNum,strs):
	#sys.stdout.write("Case #"+str(caseNum)+": "+strs+"\n")
	my_file2.write("Case #"+str(caseNum)+": "+strs+"\n")

my_file = open('Input.txt',"r")
my_file2 = open('Output.txt', "w")
N = int(my_file.readline())
for case in range(1,N+1):
	printCase(case,Solve())
my_file.close()
my_file2.close()