import bisect

def optimal_game(playerBlocks, enemyBlocks):
	enemyBlocks = enemyBlocks[:]

	winCount = 0

	blocksCount = len(playerBlocks)
	for i in range(0, blocksCount):
		blockIndex = blocksCount - i - 1
		playerBlock = playerBlocks[blockIndex]

		if playerBlock > enemyBlocks[blockIndex]:
			# player won, enemy removes minimal block
			winCount += 1
			enemyBlocks.pop(0)
		else:
			# enemy uses minimal block greater than player's
			enemyBlockIndex = bisect.bisect(enemyBlocks, playerBlock)
			enemyBlocks.pop(enemyBlockIndex)

	return winCount

def cheat_game(playerBlocks, enemyBlocks):
	playerBlocks = playerBlocks[:]
	enemyBlocks = enemyBlocks[:]

	winCount = 0

	blocksCount = len(playerBlocks)
	for i in range(0, blocksCount):
		playerMax = playerBlocks[blocksCount - i - 1]
		enemyMax = enemyBlocks.pop()

		if enemyMax > playerMax:
			# can't win, gave minimal block
			playerBlocks.pop(0)
		else:
			# player won, removes minimal block greater than enemy's
			winCount += 1

			playerBlockIndex = bisect.bisect(playerBlocks, enemyMax)
			playerBlocks.pop(playerBlockIndex)

	return winCount

fin = open('input.txt')
lines = fin.read().split("\n")

testsCount = int(lines[0])

for testCase in range(1, testsCount + 1):
	curLine = (testCase - 1) * 3 + 1

	playerBlocks = sorted([float(x) for x in lines[curLine + 1].split()])
	enemyBlocks = sorted([float(x) for x in lines[curLine + 2].split()])

	print "Case #" + str(testCase) + ":",
	print cheat_game(playerBlocks, enemyBlocks),
	print optimal_game(playerBlocks, enemyBlocks)

	pass