solutions = []
with open('cookie.in', 'r') as f:
	test_cases = int(f.readline().strip())

	for t in xrange(test_cases):
		R = 2.0
		C, F, X = map(float, f.readline().strip().split())
		total_time = 0.0
		while (X-C)/R > (X)/(R+F):
			total_time += C/R
			R += F
		total_time += X/R
		solutions.append('Case #{}: {:.7f}\n'.format(t+1, total_time))

with open('cookie.out', 'w+') as f:
	f.writelines(solutions)
	f.seek(0)
	print f.read()
