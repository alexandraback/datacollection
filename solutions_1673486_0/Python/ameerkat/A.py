import operator
# pressing backspace n times
def m_2(p, u, l, n):
	r = l - u
	if n != 0:
		pc = reduce(operator.mul, p[0:-n])
	else:
		pc = reduce(operator.mul, p)
	return pc*(2*n + r + 1) + (1-pc)*(2*n + r + l + 2)
	
def a1(p, u, l):
	om = l + 2
	for i in range(u):
		m = m_2(p, u, l, i)
		if m < om:
			om = m
	return om

if __name__ == "__main__":
	f = open("A-small-attempt0.in")
	T = int(f.readline().strip())
	for i in range(T):
		A,B = map(int, f.readline().strip().split())
		p = map(float, f.readline().strip().split())
		print "Case #" + str(i+1) + ": " + "%.6f" % a1(p, A, B)
	