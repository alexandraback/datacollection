from math import *

t = int(input())

for itr in range(0,t):
	n = int(input())
	a = []
	b = []
	count = 0
	for i in range(0,n):
		line = (input()).split()
		a.append(line[0])
		b.append(line[1])
	for i in range(0,n):
		if a.count(a[i])>1 and b.count(b[i])>1:
			count+=1
	print("Case #"+str(itr+1)+": "+str(count))
