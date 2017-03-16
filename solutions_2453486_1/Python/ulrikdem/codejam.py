# Hezekiah's Code Jam Solution
# Usage: python3 codejam.py < file.in > file.out

def more(line):
	return 4

def solve(lines):
	empty = 0

	# Test for row
	for row in range(0, 4):
		for player in ["X", "O"]:
			count = lines[row].count(player)
			if count == 4 or (count == 3 and "T" in lines[row]):
				return player + " won"
		empty += lines[row].count(".")

	# Test for column
	for column in range(0, 4):
		count = {"X": 0, "O": 0, "T": 0, ".": 0}
		for row in range(0, 4):
			count[lines[row][column]] += 1
			for player in ["X", "O"]:
				if count[player] == 4 or (count[player] == 3 and count["T"] == 1):
					return player + " won"

	# Test for diagonal
	count = [{"X": 0, "O": 0, "T": 0, ".": 0}, {"X": 0, "O": 0, "T": 0, ".": 0}]
	for index in range(0, 4):
		count[0][lines[index][index]] += 1
		count[1][lines[index][3 - index]] += 1
	for player in ["X", "O"]:
		for diagonal in range(0, 2):
			if count[diagonal][player] == 4 or (count[diagonal][player] == 3 and count[diagonal]["T"] == 1):
				return player + " won"

	# Draw or incomplete game
	if empty:
		return "Game has not completed"
	else:
		return "Draw"

def main():
	cases = int(input())
	for case in range(1, cases + 1):
		lines = [input()]
		for line in range(0, more(lines[0])):
			lines.append(input())
		print("Case #" + str(case) + ": " + solve(lines))

main()
