t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    n = int(raw_input())

    if n == 0:
    	print "Case #{}: INSOMNIA".format(i)
    	continue

    tmp = 0
    counter = 1
    numberSet = set()

    while 1:
    	tmp += n
    	newSet = set(map(int, str(tmp)))
    	numberSet.update(newSet)
    	if len(numberSet) == 10:
    		print "Case #{}: {}".format(i, counter*n)
    		break

    	counter += 1