import math
t = input()
def C(n,k):
	#print n,k
	if(k > n):
		return 0
	m = max(k,n-k)
	prod = 1
	for i in range(n,m,-1):
		prod = prod*i
	for i in range(1,n-m+1,1):
		prod = prod/i
	return prod
	
def binom(n,k,t):
	sum = 0
	for i in range(k,t+1):
		sum = sum+C(n,i)
		#print sum
	sum = sum*(0.5**n)
	return sum
	
	
for i in range(t):
	a,x,y = map(int,raw_input().split())
	odd = 1
	while True:
		if a < (odd*(odd+1))/2:
			break
		else:
			odd = odd +2
	odd = odd -2
	if (abs(x) + y) < odd:
		print "Case #"+str(i+1)+": 1.0"
	elif (abs(x) + y) > odd + 2 or y == odd+1:
		print "Case #"+str(i+1)+": 0.0"
	else:
		r = a - odd*(odd+1)/2
		if r <= odd+1:
			prob = binom(r,y+1,odd+1)
		else:
			v = r - odd -1
			if y<v:
				prob = 1.0
			else:
				prob = binom(r-2*v,y+1-v,odd+1-v)
		print "Case #"+str(i+1)+": "+str(prob)
		