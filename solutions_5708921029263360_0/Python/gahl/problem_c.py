def one(line):
	J, P, S, K = [int(a) for a in line.split(' ')]
	limits = [J*P*K, J*P*S]
	opts = []
	if min(limits) == limits[1]:
		# limiter is total options
		for j in xrange(1, J+1):
			for p in xrange(1, P+1):
				for s in xrange(1, S+1):
					opts.append([j, p, s])
	else:
		s = 1
		for j in xrange(1, J+1):
			for p in xrange(1, P+1):
				for k in xrange(1, K+1):
					opts.append((j, p, s))
					s = s + 1
					if s > S:
						s = 1
		d = {}
		to_rem = set()
		last_rem = -1
		for i, o in enumerate(opts):
			ll = [(0, o[1], o[2]), (o[0], 0, o[2])]
			for l in ll:
				if l not in d:
					d[l] = 0

			for l in ll:
				if d[l] == K:
					to_rem.add(i)
					last_rem = i
					break
			
			if last_rem == i:
				continue

			for l in ll:
				d[l] += 1

		#print to_rem
		no = []
		for i, o in enumerate(opts):
			if i not in to_rem:
				no.append(o)
		#print "len(opts): %d, len(no): %d" % (len(opts), len(no))
		opts = no


	s = [str(len(opts))]
	for o in opts:
		s.append('\n')
		s.append(' '.join(str(a) for a in o))
	return ''.join(s)


def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		num = raw_input()
		#print "Case #%d (%s): %s" % (x + 1, num, one(num))
		print "Case #%d: %s" % (x + 1, one(num))

main()