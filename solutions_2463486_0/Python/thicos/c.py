fairsquare = []

def check_palin(n):
	s = str(n)
	l = len(s)
	if (l == 1): return True
	for i in xrange(l/2):
		if (s[i] != s[l-i-1]): return False
	return True
	
for i in xrange(4):
	b = pow(10, i)
	e = pow(10, i+1)
	j = b
	while(j < e):
		s = str(j)
		s += s[:-1][::-1]
		n = int(s)
		n = n*n
		if (check_palin(n)): 
			fairsquare.append(n)
		j+=1
	j = b
	while(j<e):
		s = str(j)
		s += s[::-1]
		n = int(s)
		n = n*n
		if (check_palin(n)): 
			fairsquare.append(n)
		j+=1

T = int(raw_input())
for t in xrange(T):
	l = raw_input().split()
	a = int(l[0])
	b = int(l[1])
	res = 0
	for i in fairsquare:
		if (i >= a and i <= b): res+=1
	print "Case #%d: %d"%(t+1,res)