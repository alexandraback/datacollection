import math
import sys
import itertools
def gcd(a,b):
	x = max(a,b)
	y = min(a,b)
	while y != 0:
		tmp = y
		y = x % y
		x = tmp
	return x
def Solve():
	N,M,K = [int(x) for x in my_file.readline().split()]
	if M == 1 or M == 2:
		return str(K)
	l = M-2
	cnt = K
	for i in range(K,0,-1):
		can = True
		p = int(i-1/l)
		if i%l == 0:
			n = 2*p+2*l+2+i
			if N-2 < p+1:
				can = False
		elif i > l:
			n = 2*p+2*l+1+i
			if N-2 < p+1:
				can = False
		else:
			if N-2 < 1:
				can = False
			n = 2*i+2+i
		#print(i,n,n-i,max(K-n,0),max(K-n,0)+n-i)
		if can:
			cnt = min(cnt,max(K-n,0)+n-i)
	return str(cnt)
	


def printCase(caseNum,strs):
	sys.stdout.write("Case #"+str(caseNum)+": "+strs+"\n")
	my_file2.write("Case #"+str(caseNum)+": "+strs+"\n")

my_file = open('Input.txt',"r")
my_file2 = open('Output.txt', "w")
T = int(my_file.readline())
for case in range(1,T+1):
	#Solve()
	printCase(case,Solve())
my_file.close()
my_file2.close()