f = open('C-small-attempt0.in')
output = open('ResultC-small.out', 'w')

cases = int(f.readline())

for i in xrange(1, cases + 1):
	low, high = f.readline().split()
	
	pairs = set()
		
	for n in xrange(int(low), int(high) + 1):
		if len(set(str(n))) == 1:
			continue
		m = str(n)
		
		for _ in xrange(len(m) - 1):
			m = m[-1] + m[:-1]
			
			if n < int(m) and int(m) <= int(high) and int(low) <= int(m) :
				pairs.add((n, m))
		
	output.write('Case #%d: %d\n' % (i, len(pairs)))