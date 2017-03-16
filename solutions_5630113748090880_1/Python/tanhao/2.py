import numpy as np
f = open("2.in")
test_sum = int(f.readline()[:-1])
for test_case in xrange(1, test_sum+1):
	n = int(f.readline()[:-1])
	flags = np.zeros(3000, dtype = np.uint8)
	for line_iter in xrange(2*n-1):
		num_list = [int(x) for x in f.readline().split()]
		for x in num_list:
			flags[x] = flags[x] ^ 1
	
	print "Case #%d:" % (test_case),
	
	cnt = 1
	#print flags
	for rank, value in zip(range(0, len(flags) + 1), flags):

		if value == 1:
			if cnt == n:
				print rank
			else:
				print rank,
			cnt += 1

			
			

	
