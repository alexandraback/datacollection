import math

def incPlayer(player, enemy):
	countFixes = math.log((enemy - player) / float(player - 1) + 1, 2)
	countFixes = int(countFixes) + 1

	return (int(player + (player - 1) * (math.pow(2, countFixes) - 1)), countFixes)

def truncSteps(steps):
	fixedSteps = []

	for i in range(0, len(steps)):
		step = steps[i]
		stepPlayer = step[0]
		stepFixes = step[1]

		validStep = True
		for j in range(0, len(steps)):
			if i != j and steps[j][0] >= stepPlayer and steps[j][1] < stepFixes:
				validStep = False
				break

		if validStep:
			fixedSteps.append(step)

	return fixedSteps

fin = open('input.txt')
lines = fin.read().split("\n")

countTests = int(lines[0])
for testCase in range(1, countTests + 1):
	startLine = (testCase - 1) * 2 + 1

	l1 = lines[startLine].split()
	l2 = lines[startLine + 1].split()

	player = int(l1[0])

	enemies = [int(x) for x in l2]
	enemies.sort()

	steps = [(player, 0)]

	countFixes = 0
	for i in range(0, len(enemies)):
		newSteps = []

		enemy = enemies[i]
		for step in steps:
			stepPlayer = step[0]
			stepFixes = step[1]

			if stepPlayer > enemy:
				newSteps.append((stepPlayer + enemy, stepFixes))
			else:
				# try remove enemy
				newSteps.append((stepPlayer, stepFixes + 1))

				# try add smaller enemies
				if stepPlayer > 1:
					incedPlayer = incPlayer(stepPlayer, enemy)
					newSteps.append((incedPlayer[0] + enemy, stepFixes + incedPlayer[1]))

		steps = truncSteps(newSteps)

	solution = min([step[1] for step in steps])
	print "Case #" + str(testCase) + ": " + str(solution)