t = int(input())

for test in range(1, t + 1):
	a = [input() for i in range(4)]
	input()
	
	hasDot = False
	for i in range(4):
		for j in range(4):
			if a[i][j] == '.':
				hasDot = True

	d = [[(i, j) for i in range(4)] for j in range(4)]
	d += [[(i, j) for j in range(4)] for i in range(4)]
	d += [ [(i, i) for i in range(4)], [(i, 3 - i) for i in range(4)]]
		
	winX = False
	winO = False
	for x in d:
		winXR = True
		winOR = True
		for (u, v) in x:
			if a[u][v] == '.':
				winXR = False
				winOR = False
			if a[u][v] == 'O':
				winXR = False
			if a[u][v] == 'X':
				winOR = False
		if winXR:
			winX = True
		if winOR:
			winO = True

	print("Case #" + str(test) + ": " + ("X won" if winX else "O won" if winO else "Game has not completed" if hasDot else "Draw"))