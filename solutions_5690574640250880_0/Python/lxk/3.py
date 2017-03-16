def build_figure(rows, cols):
	figure = []
	for i in range(0, rows):
		figure.append(cols)
	return figure

def append_rest(figure, rest, rows, columns):
	figRows = len(figure)
	figCols = figure[0]

	if figRows < rows:
		# append rest points as last row
		figure.append(rest)
		return figure
	elif figCols < columns:
		# append rest points as last column
		for i in range(0, rest):
			figure[i] += 1
		return figure

	return None

def find_solution(rows, columns, mines):
	if rows == 1:
		return build_figure(1, columns - mines)
	elif columns == 1:
		return build_figure(rows - mines, 1)

	totalPoints = rows * columns - mines
	if totalPoints == 1:
		return build_figure(1, 1)

	for figRows in range(2, rows + 1):
		figCols = min(totalPoints / figRows, columns)
		restPoints = totalPoints - figRows * figCols

		if figCols <= 1 or restPoints >= columns:
			continue

		if restPoints == 0:
			# solution found
			return build_figure(figRows, figCols)
		else:
			figure = build_figure(figRows, figCols)

			if restPoints == 1:
				# try to get last point and append it to rest
				if not (figRows > 2 and figCols > 2):
					continue

				figure[figRows - 1] -= 1
				restPoints += 1

			figure = append_rest(figure, restPoints, rows, columns)
			if figure is not None:
				return figure

	return None

fin = open('input.txt')
lines = fin.read().split("\n")

testsCount = int(lines[0])

for testCase in range(1, testsCount + 1):
	line = [int(x) for x in lines[testCase].split()]

	rows = line[0]
	columns = line[1]
	mines = line[2]

	figure = find_solution(rows, columns, mines)

	print "Case #" + str(testCase) + ":"
	if figure is None:
		print "Impossible"
	else:
		for rowIndex in range(0, rows):
			fillEnd = figure[rowIndex] if rowIndex < len(figure) else 0

			rowView = ""
			for columnIndex in range(0, columns):
				if rowIndex == 0 and columnIndex == 0:
					rowView += "c"
				elif columnIndex < fillEnd:
					rowView += "."
				else:
					rowView += "*"

			print rowView