from sys import stdin

input = stdin.readlines()
nextLine = 1

for i in range(1, 1+int(input[0])):
	line = input[nextLine].split()
	nextLine += 1
	R, N, M, K = int(line[0]), int(line[1]), int(line[2]), int(line[3])
	print "Case #1:"
	
	for r in range(R):
		line = input[nextLine].split()
		nextLine += 1
		x,y,z = 2,3,4
		prods = []

		for k in range(K):
			prod = int(line[k])
			if prod > 1:
				prods.append(prod)

		if len(prods) == 0:
			print "{0}{1}{2}".format(x,y,z)
			continue;

		if max([p % 5 for p in prods]) == 0:
			x = 5
		elif max([p % 3 for p in prods]) == 0:
			x = 3
		else:
			x = 2

		prods = [p / x for p in prods]

		if max([p % 5 for p in prods]) == 0:
			y = 5
		elif max([p % 3 for p in prods]) == 0:
			y = 3
		else:
			y = 2

		z = prods[0] / y

		print "{0}{1}{2}".format(x, y, z)