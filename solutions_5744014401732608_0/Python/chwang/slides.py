B = 4
M = 20


def build(B, M, f_out):
	routes = [1]
	for k in xrange(B-1):
		routes.append(sum(routes))

	if routes[-1] < M:
		f_out.write('IMPOSSIBLE\n')
	else:
		f_out.write('POSSIBLE\n')
		if B-2 > 0:
			f_out.write(str(0) + str(bin(M-1)[2:].zfill(B-2)) + str(1) + '\n')
		else:
			f_out.write('01\n')

		for k in xrange(B-1):
			f_out.write('0'*(k+2) + '1'*(B-k-2) + '\n')



filename = 'B-small-attempt0'
f_out = open(filename+'.out', 'w')
with open(filename+'.in') as f_in:
	T = int(f_in.readline())
	for t in xrange(T):
		B, M = f_in.readline().rstrip().split(' ')
		B = int(B)
		M = int(M)

		f_out.write('Case #' + str(t+1) + ': ')	
		build(B, M, f_out)

