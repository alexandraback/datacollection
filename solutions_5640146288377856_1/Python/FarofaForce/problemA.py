if __name__ == '__main__':
	T = int(raw_input())

	for i in xrange(0, T):
		input_line = raw_input().split()
		R = int(input_line[0])
		C = int(input_line[1])
		W = int(input_line[2])

		result = 0

		if (C%W) == 0:
			result = (C/W)*R + W-1
		else:
			result = (C/W)*R + W

		print "Case #%d: %s" %(i+1, result)