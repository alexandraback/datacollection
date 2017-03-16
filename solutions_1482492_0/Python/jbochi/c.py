import math

def solve(T, a, d):
	v = 0
	t = 0
	lastct, lastcx, cv = 0, 0, 0
	ct, cx = 0, 0
	for ct, cx in T:
		if ct > 0:
			cv = (cx - lastcx) / (ct - lastct)

		lastct, lastcx = ct, cx


	if cx > D:
		if cv == 0:
			print T
			ct = 0
		else:
			ct = lastct + (D - lastcx) / cv
	mint = math.sqrt(2.0 * D / a)


	return max(mint, ct)

if __name__ == '__main__':
	output = []
	with open('B-small-attempt1.in') as f:
		def input_int():
			return int(f.readline())

		n_tests = input_int()
		for i_test in xrange(n_tests):
			D, N, A = f.readline().strip().split(' ')
			D = float(D)
			N = int(N)
			A = int(A)
			value = [D, N, A]
			T = []
			for i in xrange(N):
				t, x = map(float, f.readline().strip().split(' '))
				T.append([t, x])

			As = map(float, f.readline().strip().split(' '))
			output.append("Case #%d:\n" % (i_test + 1))
			for a in As:
				s = solve(T, a, D)
				output.append("%.6f\n" % s)

	for l in output:
		print l

	with open('x.out', 'w') as f:
		f.writelines(output)
