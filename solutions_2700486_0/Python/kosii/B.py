input_file_name = 'B-small-attempt0.in'
output_file_name = 'B-small-attempt0.out'

from operator import mul    # or mul=lambda x,y:x*y

nCk = lambda n,k: int(round(
    reduce(mul, (float(n-i)/(i+1) for i in range(k)), 1)
))

def n_all(n):
	return n + 1 + 4 * (n + 1) * n / 2

def n_perim(n):
	return 1 + n * 4

def at_least_from(x, y):
	s = 0
	for i in xrange(y, x+1):
		s += 0.5**x * nCk(x, i)
	return s

with open(input_file_name) as input, open(output_file_name, 'w') as output:
	T = int(input.readline())
	print T
	for i in xrange(T):
		N, X, Y = map(int, input.readline().split())
		print N, X, Y
		row = abs(X) + abs(Y)
		row /= 2
		print "sor", row
		a = n_all(row - 1)
		needed = n_all(row - 1) + row * 2 + Y + 1

		print "kockaszamok", a, needed
		format = "Case #{i}: {p}\n"
		if N >= needed:
			output.write(format.format(i=i+1, p=1.0))
			print "			1 val"
		elif N <= a:
			output.write(format.format(i=i+1, p=0.0))
			print "			0 val"
		elif X == 0:
			output.write(format.format(i=i+1, p=0.0))
			print "			0 val -----"
		else:
			p = at_least_from(N-a, Y + 1)
			output.write(format.format(i=i+1, p=p))
			print "			pozitiv val", p
