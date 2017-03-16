# Hezekiah's Code Jam Solution
# Usage: python3 codejam.py < file.in > file.out

def more(line):
	return 1

def least(first, second):
	if first <= second:
		return first
	else:
		return second

def solution(size, motes):
	if len(motes) == 0:
		return 0

	if size > motes[0]:
		return solution(size + motes[0], motes[1:])

	size = size * 2 - 1
	added = 1
	while size <= motes[0]:
		size = size * 2 - 1
		added += 1
	return least(solution(size + motes[0], motes[1:]) + added, len(motes))

def solve(lines):
	size = int(lines[0].split(" ")[0])
	motes = [int(mote) for mote in lines[1].split(" ")]
	motes.sort()

	if size == 1:
		return str(len(motes))
	else:
		return str(solution(size, motes))

def main():
	cases = int(input())
	for case in range(1, cases + 1):
		lines = [input()]
		for line in range(0, more(lines[0])):
			lines.append(input())
		print("Case #" + str(case) + ": " + solve(lines))

main()
