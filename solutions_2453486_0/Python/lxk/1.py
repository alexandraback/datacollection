def check(field, start, offset, ch):
	for i in range(0, 4):
		if not field[start + offset * i] in (ch, 'T'):
			return False
	return True

def checkall(field, ch):
	for i in range(0, 4):
		# horizontal
		if check(field, i * 4, 1, ch):
			return True

		# vertical
		if check(field, i, 4, ch):
			return True

	# diagonal
	return check(field, 0, 5, ch) or check(field, 3, 3, ch)

fin = open('input.txt')
lines = fin.read().split("\n")

countTests = int(lines[0])
for testCase in range(1, countTests + 1):
	startLine = (testCase - 1) * 5 + 1

	field = ""

	draw = True
	for lineIndex in range(startLine, startLine + 4):
		line = lines[lineIndex]

		field += line
		if '.' in line:
			draw = False

	prefix = 'Case #' + str(testCase) + ': '
	if checkall(field, 'X'):
		print prefix + 'X won'
	elif checkall(field, 'O'):
		print prefix + 'O won'
	elif draw:
		print prefix + 'Draw'
	else:
		print prefix + 'Game has not completed'