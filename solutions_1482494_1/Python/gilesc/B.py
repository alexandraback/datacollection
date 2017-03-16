import fileinput, operator

lines = fileinput.input()
lines.next()
case = 0
while True:
	case += 1
	n = int(lines.next())
	levels = [map(int,lines.next().split()) for i in range(n)]
	halfway = []

	stars = 0
	times = 0
	#print "***"
	while levels or halfway:
		#print stars, levels, halfway
		levels.sort(key=operator.itemgetter(1))
		if levels and levels[0][1] <= stars:
			levels.pop(0)
			stars += 2
			times += 1
			continue
		halfway.sort()
		if halfway and halfway[0] <= stars:
			halfway.pop(0)
			times += 1
			stars += 1
			continue
		levels.reverse()
		if levels:
			pop = None
			for i,(one,two) in enumerate(levels):
				if one <= stars:
					pop = i
					halfway.append(two)
					stars += 1
					times += 1
					break
			if pop is not None:
				levels.pop(pop)
				continue
		break
	if levels or halfway:
		result = "Too Bad"
	else:
		result = str(times)
	print "Case #%d:" % case, result


		
		
