import fileinput
import operator
product = lambda xs: reduce(operator.mul, xs)

lines = fileinput.input()
lines.next()
case = 0
while lines:
	case += 1
	A, B = map(int,lines.next().split())
	p = map(float, lines.next().split())
	p_correct = lambda i: product(p[:(A-i)])

	expected = B+2
	for i in range(0,A):
		pcor = p_correct(i)
		exp = (2*i+B-A+1) + (B+1)*(1-pcor)
		if exp < expected:
			expected = exp
	print "Case #%i:" % case, expected

