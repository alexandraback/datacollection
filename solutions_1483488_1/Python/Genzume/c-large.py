file = open('C-large.in', 'r')
out = open('C-large.out', 'w')
lines = int(file.readline().rstrip())

d = {}
for t in range(1, lines + 1):
	line = file.readline().rstrip().split()
	A, B = int(line[0]), int(line[1])
	
	pairs = set()
	for x in range(A, B+1):
		str_x = str(x)
		if x not in d:
			if x > 9:
				res = []
				for i in range(1, len(str_x)):
					s = int(str_x[i:] + str_x[:i])
					res.append(s)
				d[x] = res
			else:
				d[x] = []
		
		for ans in d[x]:
			if ans > x and ans <= B:
				pairs.add((x, ans))
			
	answer = len(pairs)
	result = "Case #%d: %d" % (t, answer)
	out.write(result + '\n')
	print result

file.close()
out.close()