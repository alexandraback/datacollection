import math
f = open("in.txt")
T = int(f.readline())

w = open("out.txt", "w")

def solveTestcase():
	global i
	answer = ""
	x, y = map(int, f.readline().split())
	curx, cury = 0, 0
	while curx != x:
		if curx < x: # move right
			answer += "WE"
			curx += 1
		elif curx > x: # move left
			answer += "EW"
			curx -= 1

	while cury != y:
		if cury < y: # move up
			answer += "SN"
			cury += 1
		elif cury > y: # move down
			answer += "NS"
			cury -= 1
	w.write("Case #" + str(i + 1) + ": " + answer + "\n")
	return None

for i in range(T):
	solveTestcase()