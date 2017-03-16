import sys

for tc in xrange(1, int(sys.stdin.readline())+1):
	num_in = [int(w) for w in sys.stdin.readline().split()]
	n = num_in[0]
	val = num_in[1:]
	exclude = True
	exclude_val = [False for v in val]
	avg = 0
	x = sum(val)
	while exclude:
		exclude = False
		include_val = [v for k, v in enumerate(val) if exclude_val[k] == False]
		if len(include_val) == 0:
			avg = 0
			break;
		avg = float(sum(include_val) + sum(val)) / len(include_val)
		#print avg
		for i, v in enumerate(val):
			if val[i] >= avg and exclude_val[i] == False:
				exclude = True
				exclude_val[i] = True
	output = []
	for i, v in enumerate(val):
		if exclude_val[i] == True:
			output.append(str(0.000000))
		else:
			output.append(str((avg - val[i]) * 100/x))
	print "Case #%d: %s" % (tc, " ".join(output))

