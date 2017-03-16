import fileinput

myfile = fileinput.input();
currentcase = 0
maxcases = 0

for line in myfile:
	if fileinput.isfirstline():
		maxcases = int(line.strip())
		continue

	currentcase += 1
	(x, y) = line.strip().split()

	x = int(x)
	y = int(y)
	path = ""
	curx = 0
	cury = 0

	for i in range(1,501):
		if curx == x and cury == y:
			break

		if curx != x:
			if (curx + i) <= x:
				curx += i
				path += "E"
				continue
			elif (curx - i) >= x:
				curx -= i
				path += "W"
				continue
			elif (curx + i) > x:
				curx += i
				path += "E"
				continue
			else:
				curx -= i
				path += "W"
				continue

		if (cury + i) <= y:
			cury += i
			path += "N"
			continue
		elif (cury - i) >= y:
			cury -= i
			path += "S"
			continue
		elif (cury + i) > y:
			cury += i
			path += "N"
			continue
		else:
			cury -= i
			path += "S"
			continue

		if i == 500:
			path = ""

	print "Case #"+str(currentcase)+": "+str(path)

	if maxcases == currentcase:
		break