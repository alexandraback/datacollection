import sys

T = int(sys.stdin.readline().strip())

def read(n):
	m = n
	covered = range(10)
	while len(covered)>0:
		remove = []
		for x in covered:
			if str(x) in str(m):
				remove.append(x)
		covered = [x for x in covered if x not in remove]
		m += n
	return m - n

for t in range(T):
	n = int(sys.stdin.readline().strip())
	if n == 0:
		print "Case #%d: INSOMNIA"%(t+1)
	else:
		print "Case #%d: %d"%(t+1, read(n))



