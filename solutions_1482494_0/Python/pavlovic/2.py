import sys

t = int(sys.stdin.readline())
for i in range(t):
	n = int(sys.stdin.readline())

	level_done = []
	a = []
	b = []
	for j in range(n):
		inputline = sys.stdin.readline().strip()
		inputparams = inputline.split()

		a.append(int(inputparams[0]))
		b.append(int(inputparams[1]))
		level_done.append(0)

	total_levels_done = 0
	total_tries = 0
	total_stars_earned = 0
	any_level_done = True

	while any_level_done:
		any_level_done = False
		for j in range(n):
			if (0 == level_done[j]) and (b[j] <= total_stars_earned):
				level_done[j] = 2
				total_levels_done += 1
				total_tries += 1
				total_stars_earned += 2
				any_level_done = True
				break
		else:
			for j in range(n):
				if (1 == level_done[j]) and (b[j] <= total_stars_earned):
					level_done[j] = 2
					total_levels_done += 1
					total_tries += 1
					total_stars_earned += 1
					any_level_done = True
					break
			else:
				index = -1
				for j in range(n):
					if (0 == level_done[j]) and (a[j] <= total_stars_earned) and ((-1 == index) or (b[j] > b[index])):
						index = j

				if -1 != index:
					level_done[index] = 1
					total_tries += 1
					total_stars_earned += 1
					any_level_done = True

	print "Case #" + str(i + 1) + ": " + (str(total_tries) if total_levels_done == n else "Too Bad")

