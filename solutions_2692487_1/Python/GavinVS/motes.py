from sys import stdin

def eatPossible(size, motes): #motes is sorted
	notEaten = []
	for i in range(len(motes)):
		if motes[i] < size:
			size += motes[i]
		else:
			notEaten.append(motes[i])
	return size, notEaten

input = stdin.readlines()

for i in range(1, 1+int(input[0])):
	line = input[2 * i - 1].split()
	A, N = int(line[0]), int(line[1])
	motes = []
	line = input[2 * i].split()

	for n in range(N):
		motes.append(int(line[n]))

	motes.sort()
	size, notEaten = eatPossible(A, motes)

	minMoves = len(notEaten)
	moves = 0
	oldSize = 0

	while notEaten and oldSize != size:
		oldSize = size
		moves += 1
		#increase by max size (size - 1)
		size, notEaten = eatPossible(size * 2 - 1, notEaten)
		minMoves = min(moves + len(notEaten), minMoves)

	print "Case #{0}: {1}".format(i, minMoves)