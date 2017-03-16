from __future__ import print_function
from math import *
from sets import Set 
def digs(S,n):
	while n:
		S.add(n%10)
		n/=10
def ans(n):
	S = Set()
	num = 0
	cnt = 0
	while len(S) != 10:
		num+=n
		digs(S,num)
		cnt+=1
		if cnt >100000:
			return "INSOMNIA"
	return num
f = open('out.txt','w')
g = open('inp.txt','r')	
t = int(g.readline())
for tt in range(1,t+1):
	n = int(g.readline())
	f.write("Case #"+str(tt)+": "+str(ans(n))+"\n")





