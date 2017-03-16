import fileinput
stdin = fileinput.input()

def solveCase():
	# farm cost, farm rate, target
	c, f, x = map(float,stdin.next().split())
	# farm 1 at time c/2
	# farm 2 at time c/2 + c/(2+f)
	# farm 3 at time c/2 + c/(2+f) + c/(2+2*f)
	# ...
	rate = lambda n: 2+n*f
	k = 0
	tLast = 0
	finTime = tLast + x/rate(k)
	while True:
		# try building an extra farm
		tLast += c/(2+k*f)
		k += 1
		finTime2 = tLast + x/rate(k)
		if finTime2>finTime:
			return finTime
		finTime = finTime2

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())