file = open('b.in', 'r')
out = open('b.out', 'w')
lines = int(file.readline().rstrip())

for i in range(1, lines + 1):
	line = file.readline().rstrip().split()
	
	numGooglers = int(line[0])
	surprises = int(line[1])
	p = int(line[2])
	scores = map(int, line[3:])
	
	answer = 0
	
	for score in scores:
		third = score // 3
		second = (score - third) // 2
		first = score - second - third
		
		trip = (first, second, third)
		
		if trip[0] >= p:
			answer += 1
		elif surprises > 0 and trip[0] <= trip[2] + 1:
			if trip[0] == trip[1] and trip[0] + 1 >= p and trip[0] > 0:
				answer += 1
				surprises -= 1
			
	result = "Case #%d: %d" % (i, answer)
	out.write(result + '\n')
	print result

file.close()