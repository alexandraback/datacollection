
T = int(raw_input())
for i in xrange(1,T+1):
	pancakes = raw_input() + '+'
	count = 0
	for j in xrange(len(pancakes)-1):
		if pancakes[j] != pancakes[j+1]:
			count += 1

	print "Case #{}: {}".format(i, count)