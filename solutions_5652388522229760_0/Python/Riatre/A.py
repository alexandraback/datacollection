def wtf(x):
	st = set()
	i = 1
	while len(st) != 10:
		st = st.union(set(str(i * x)))
		i += 1
	return (i-1)*x

T = int(raw_input())
for i in xrange(T):
	print 'Case #%d:' % (i+1),
	N = int(raw_input())
	if N == 0:
		print 'INSOMNIA'
	else:
		print wtf(N)
	