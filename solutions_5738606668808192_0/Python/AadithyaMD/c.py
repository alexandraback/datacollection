# input n is always odd, if n is prime return 0 else a factor
def nprime(n):
	if n < 9: return 0
	if n%3 == 0: return 3
	r = int(n**0.5)
	f = 5
	while f <= r:
		if n%f == 0: return f
		if n%(f+2) == 0: return f+2
		f +=6
	return 0 

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	n,j = [int(s) for s in raw_input().split(" ")]
	#j = int(raw_input())

	k = 2**(n-2)
	print "Case #{}:".format(i)

	for x in xrange(0,k):  # it is the entire range

		if j == 0: break

		numl=[1]	# it is the list of digits
		s = "{0:b}".format(x)
		a = n - 2 - len(s)
		while a>0:
			numl.append(0)
			a = a-1

		for n1 in s:
			numl.append(int(n1))
		numl.append(1)
		basel=[0,0,0,0,0,0,0,0,0]

		for n1 in numl:
			for j1 in xrange(0,9):
				basel[j1] = basel[j1]*(j1+2) + n1
		
		proceed = True
		fl=[]
		for n1 in basel:
			val = nprime(n1)
			if val == 0:   # ie num is prime 
				proceed = False
				break
			else:
				fl.append(val)

		if proceed:
			print "{}".format(basel[8]),
			for n1 in fl:
				print " {}".format(n1),
			print ''
			j = j-1
