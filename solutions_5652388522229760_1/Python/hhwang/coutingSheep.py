
T = int(raw_input())
for i in xrange(1,T+1):
	N = int(raw_input())
	digits = {}
	for j in xrange(10):
		digits[j] = j
	if N==0:
		print "Case #{}: {}".format(i, "INSOMNIA")
	else:
		count = 0
		while digits != {}:
			count += N
			temp = count
			while temp>0:
				to_remove = temp % 10
				temp = temp / 10
				if to_remove in digits:
					del digits[to_remove] 
		print "Case #{}: {}".format(i, count)