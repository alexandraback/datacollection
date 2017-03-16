def amount(r,n):
	return 2*n*r+(n*n+n)*2-3*n

for T in range(int(raw_input())):
	MAX = 10**20
	r,t = map(int, raw_input().split())
	a = 1
	b = MAX
	while b-a>1:
		middle = int((a+b)/2)
		if (amount(r,middle)<=t):
			a = middle
		else:
			b = middle
	if amount(r,b)<=t:
		result = b
	else:
		result = a
	print "Case #%d: %d"%(T+1,result)

