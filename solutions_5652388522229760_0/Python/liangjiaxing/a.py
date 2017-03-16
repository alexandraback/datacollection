re = int(raw_input())

for cas in range(re):
	n = int(raw_input())
	print "Case #%d:" % (cas + 1),
	if n == 0:
		print "INSOMNIA"
		continue
	m = n
	l = set(str(m))
	while len(l) < 10:
		m += n
		l = l | set(str(m))
		#print l
	print m
