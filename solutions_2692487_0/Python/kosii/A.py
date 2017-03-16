file_prefix = 'A-small-attempt4'

input_file_name = file_prefix + '.in'
output_file_name = file_prefix + '.out'
def harrrr(armin, mote):
	if armin == 1 and mote > 0:
		return 1000000, armin
	c = 0
	while armin <= mote:
		c += 1
		armin += (armin - 1)
	return c, armin

with open(input_file_name) as input, open(output_file_name, 'w') as output:
	T = int(input.readline())
	for t in xrange(T):
		A, N = map(int, input.readline().split())
		motes = map(int, input.readline().split())
		print A, N, sorted(motes)
		added = []
		for i, mote in enumerate(sorted(motes)):
			if mote < A:
				A += mote
				added.append(0)
			else:
				l, A = harrrr(A, mote)
				added.append(l)
		print added
		print sum(added)
		sum_added = sum(added)
		accumulated = 0
		removed = 0
		for i, a in enumerate(added):
			print accumulated, removed, a, N - i
			if sum_added > accumulated + N - i:
				added = accumulated
				removed = N - i
				break
			else:
				accumulated += a
		print 'result', accumulated, removed
		output.write("Case #{t}: {n}\n".format(t=t+1, n=(accumulated + removed)))