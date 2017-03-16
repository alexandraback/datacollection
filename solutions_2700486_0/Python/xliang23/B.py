import sys
f = open(sys.argv[1], 'r')
T = int(f.readline().split()[0])


def dfs(i, n, X, Y, strings):
	global counter
	global array2d
	#print "DFS: " + str(i) + " "+ str(strings)
	if i == n:
		if array2d[X][Y] == 1:
			counter += 1
			#print strings
	else:
		for j in xrange(100):
			if array2d[0][50-j] == 1:
				j = j - 2
				y = 50-j
				# falling left
				# must be able to fall left or cant fall right
				if array2d[-1][y-1] == 0 or array2d[1][y-1] == 1:
					# then it must fall left or stay where it is
					for k in xrange(y+1):
						# if it falls left
						if array2d[-(1+k)][y-k-1] == 1 or k == y:
							array2d[-k][y-k] = 1
							#strings.append("L")
							#print "Call Left"
							dfs(i+1, n,X,Y, strings)
							#print "End Left"
							#strings.pop()
							#print "After popping: " + str(strings)
							#pull diamond back out
							array2d[-k][y-k] = 0
							break
				else:
					# must fall right
					# now fall right
					for k in xrange(y+1):
						# if it falls right
						if array2d[k+1][y-k-1] == 1 or k == y:
							array2d[k][y-k] = 1
							#strings.append("R")
							#print "Call Right"
							dfs(i+1, n,X,Y, strings)
							#print "End Right"
							#strings.pop()
							#print "After popping: " + str(strings)
							#pull diamond back out
							array2d[k][y-k] = 0
							break
				# can we fall right?
				if array2d[1][y-1] == 0 or array2d[-1][y-1] == 1:
					# then make it fall right
					for k in xrange(y+1):
						# if it falls right
						if array2d[k+1][y-k-1] == 1 or k == y:
							array2d[k][y-k] = 1
							#strings.append("R")
							#print "Call Right"
							dfs(i+1, n,X,Y, strings)
							#print "End Right"
							#strings.pop()
							#print "After popping: " + str(strings)
							#pull diamond back out
							array2d[k][y-k] = 0
							break
				# else we are falling left
				else:
					for k in xrange(y+1):
						# if it falls left
						if array2d[-(1+k)][y-k-1] == 1 or k == y:
							array2d[-k][y-k] = 1
							#strings.append("L")
							#print "Call Left"
							dfs(i+1, n,X,Y, strings)
							#print "End Left"
							#strings.pop()
							#print "After popping: " + str(strings)
							#pull diamond back out
							array2d[-k][y-k] = 0
							break
				break


for t in xrange(T):
	global counter
	global array2d
	N,X,Y = [int(x) for x in f.readline().split()]
	counter = 0
	array2d = []
	strings = []
	for i in xrange(100):
		array2d.append([])
		for j in xrange(100):
			array2d[i].append(0)
	array2d[0][-2] = 1
	if abs(X) < 45 and abs(Y) < 45:
		dfs(0, N, X, Y, strings)

	res = float(counter)/(2 ** N)

	print "Case #%d: %.9f" % (t+1, res)