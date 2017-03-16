def get_all_options(c):
	l = list(c)
	for a in xrange(len(l)):
		if l[a] != '?':
			l[a] = int(l[a])
	qc = [i for i,a in enumerate(c) if a == '?']
	for a in xrange(10**len(qc)):
		for i in qc:
			l[i] = a % 10
			a /= 10
		fin = 0
		for i,k in enumerate(reversed(l)):
			fin += 10**i*k
		yield fin


def one(s):
	c,j = s.split(' ')
	
	options_c = list(get_all_options(c))
	options_j = list(get_all_options(j))

	best_c, best_j = 99999999, 0
	for opt_c in options_c:
		for opt_j in options_j:
			if abs(opt_c - opt_j) < abs(best_c - best_j) or \
			   abs(opt_c - opt_j) == abs(best_c - best_j) and opt_c < best_c or \
			   abs(opt_c - opt_j) == abs(best_c - best_j) and opt_c == best_c and opt_j < best_j:
			   best_c, best_j = opt_c, opt_j

	best_c = str(best_c)
	best_j = str(best_j)
	best_c = '0'*(len(c) - len(best_c)) + best_c
	best_j = '0'*(len(j) - len(best_j)) + best_j
	return '%s %s' % (best_c, best_j)



def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		num = raw_input()
		print "Case #%d: %s" % (x + 1, one(num))

main()