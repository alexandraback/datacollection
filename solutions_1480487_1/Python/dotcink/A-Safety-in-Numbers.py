for t in range(int(input())):
	line = [int(w) for w in input().split()]
	print("Case #" + str(t+1), end=": ")
	the_sum = 0
	result = [1]
	for i in line[1:]:
		the_sum += i
		result.append(1)
	last = line[0]
	all_point = 2 * the_sum
	for i in range(line[0]):
		avg = all_point/last
		for j in range(1, 1+line[0]):
			if result[j]!=0:
				if line[j] >= avg:
					result[j] = 0
					all_point -= line[j]
					last -= 1
	for i in range(1,line[0]+1):
		if result[i]!=0:
			result[i] = (avg-line[i])/the_sum
	for s in result[1:]:
		print(s*100, end=" ")
	print("")
