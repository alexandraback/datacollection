f = open('B-small-attempt4.in', 'r')
ans = open('out.txt', 'w')

for case in range(int(f.readline().strip())):
	levels = []
	for i in range(int(f.readline().strip())):
		levels.append([int(x) for x in f.readline().strip().split()])

	result = 0
	stars = 0
	while result >= 0 and max([x[1] for x in levels]) != -1:
		result += 1
		# sort descending by 2-star requirements
		list.sort(levels, key=lambda x:x[1], reverse=True)
		n = -1
		for i in range(len(levels)):
			if levels[i][1] <= stars and levels[i][1] >= 0:
				n = i
				break
		if n != -1:
			if levels[n][0] == -1:
				stars += 1
			else:
				stars += 2
			levels[n] = [-1, -1]
			continue
		list.sort(levels, key=lambda x:x[0], reverse=True)
		n = -1
		for i in range(len(levels)):
			if levels[i][0] <= stars and levels[i][0] >= 0:
				n = i
				break
		if n != -1:
			stars += 1
			levels[n] = [-1, levels[n][1]]
			continue
		result = -1

	if result == -1:
		result = "Too Bad"

	ans.write("Case #" + str(case+1) + ": " + str(result) + "\n")
	print "Case #" + str(case+1) + ": " + str(result)

f.close()
ans.close()
