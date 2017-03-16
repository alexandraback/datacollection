def neq(r,p):
	a = -1*p
	b = 2*r-1
	c = 2
	n = ((-1*b)+(b**2 - 4*a*c)**decimal.Decimal(0.5))/(2*c)
	return n

def data(filename):
	import decimal
	decimal.getcontext().prec = 50
	f = open(filename,'r')
	S = f.read()
	f.close()
	A = S.splitlines()
	T = int(A[0])
	f = open(filename+' output','w')
	for i in range(T):
		l = (A[i+1]).split()
		r = decimal.Decimal(int(l[0]))
		p = decimal.Decimal(int(l[1]))
		a = -1*p
		b = 2*r-1
		c = 2
		n = ((-1*b)+(b**2 - 4*a*c)**decimal.Decimal(0.5))/(2*c)
		f.write('Case #' + str(i+1) + ': ' + str(int(n)) + '\n')
	f.close()