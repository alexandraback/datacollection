from collections import defaultdict

if __name__ == '__main__':
	output = []
	with open('A-small-attempt1.in') as f:
		def input_int():
			return int(f.readline())

		def input_ints():
			return map(int, f.readline().strip().split(' '))

		n_tests = input_int()
		for i_test in xrange(n_tests):
			N = input_int()
			H = []
			for i in xrange(N):
				H.append(map(lambda x: x-1, input_ints()[1:]))
			b = False

			roots = [[] for _ in xrange(N)]
			for child in xrange(N):
				seen = [False for _ in xrange(N)]
				P = []
				P.extend(H[child])
				#print child,
				while P:
					p = P.pop()
					#print p,
					if seen[p]:
						b = True
					seen[p] = True
					P.extend(H[p])
				#print seen

			print "Case #%d: %s\n" % (i_test + 1, "Yes" if b else "No")
			output.append("Case #%d: %s\n" % (i_test + 1, "Yes" if b else "No"))

	with open('x.out', 'w') as f:
		f.writelines(output)
