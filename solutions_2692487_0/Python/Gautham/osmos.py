import math
t = input()
for i in range(t):
	a,n = map(int,raw_input().split())
	l = map(int,raw_input().split())
	#print a
	if a == 1:
		print "Case #"+str(i+1)+": "+str(n)
		continue
	l.sort()
	k = [0]*n
	moves = 0
	for j in range(n):
		if l[j] < a:
			a = a+l[j]
			k[j] = moves
		else:
			while a <= l[j]:
				a = 2*a-1
				moves = moves + 1 
			a = a+l[j]
			k[j] = moves
	
	moves = n
	for j in range(n):
		if (k[j] + (n-j-1)) < moves:
			moves = k[j] + (n-j-1)
	
	print "Case #"+str(i+1)+": "+str(moves)