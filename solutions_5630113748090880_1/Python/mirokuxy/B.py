

T = int(raw_input())
#print 'T = %d' % T

for i in range(1, T+1):
	heights = [0] * 2501
	result = []

	N =  int(raw_input())
	#print 'N = %d' % N

	for j in range(2*N-1):
		line = raw_input()
		line = line.strip().split(' ')
		
		#print 'line: %s' % line

		for v in line:
			#print v,
			heights[int(v)] += 1
		#print

	for index,v in enumerate(heights):
		if v % 2 == 1:
			result.append(index)

	result = sorted(result)
	result = ' '.join(str(x) for x in result)
	print "Case #%d: %s" % (i, result)

