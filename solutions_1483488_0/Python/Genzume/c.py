file = open('c.in', 'r')
out = open('c.out', 'w')
lines = int(file.readline().rstrip())

for t in range(1, lines + 1):
	line = file.readline().rstrip().split()
	A, B = int(line[0]), int(line[1])
	
	pairs = set()
	for x in range(A, B+1):
		str_x = str(x)
		if x > 9:
			str_x = str(x)
			for i in range(1, len(str_x)):
				s = str_x[i:] + str_x[:i]
				if int(s) <= B and int(s) > x and (x, int(s)) not in pairs:
					pairs.add((x, int(s)))
			
	answer = set(pairs)
	result = "Case #%d: %d" % (t, len(answer))
	out.write(result + '\n')
	print result

file.close()
out.close()