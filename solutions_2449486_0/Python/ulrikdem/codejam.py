# Hezekiah's Code Jam Solution
# Usage: python3 codejam.py < file.in > file.out

def more(line):
	return int(line.split()[0])

def solve(lines):
	split = lines[0].split()
	height = int(split[0])
	width = int(split[1])
	lawn = []
	lengths = []
	for row in range(0, height):
		lawn.append([])
		line = lines[row + 1].split()
		for column in range(0, width):
			length = int(line[column])
			lawn[row].append(length)
			if length not in lengths:
				lengths.append(length)
	while len(lengths):
		maximum = max(lengths)
		lengths.remove(maximum)
		columns = []
		for row in range(0, height):
			if maximum in lawn[row]:
				maximumColumns = []
				possible = True
				for column in range(0, width):
					if lawn[row][column] == maximum:
						if column not in columns:
							maximumColumns.append(column)
					elif lawn[row][column] > maximum:
						possible = False
				if not possible:
					columns.extend(maximumColumns)
		for column in columns:
			for row in range(0, height):
				if lawn[row][column] > maximum:
					return "NO"
	return "YES"

def main():
	cases = int(input())
	for case in range(1, cases + 1):
		lines = [input()]
		for line in range(0, more(lines[0])):
			lines.append(input())
		print("Case #" + str(case) + ": " + solve(lines))

main()
