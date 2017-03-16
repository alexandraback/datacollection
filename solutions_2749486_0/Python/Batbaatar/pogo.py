def rec(x1, y1, x, y, n):
	if(n <= 6):
		if(x1 == x and y1 == y):
			return n
		else:
			for i in range(4):
				x2 = x1 + n * m[i][0]
				y2 = y1 + n * m[i][1]
				print x2, y2
				ret = rec(x2, y2, x, y, n + 1)
				if(ret != -1):
					return ret
	return -1

def solve(x, y):
	s = ""
	x1 = 0
	y1 = 0

	last = 1
	n = 1
	while(x1 != x):
		if(last == 1):
			x1 += n
			last = 2
			s += "E"
		else:
			x1 -= n
			last = 1
			s += "W"
		n += 1

	if(x1 == x and y1 == y):
		return s

	if(y > 0):
		last = 2
	else:
		last = 1
		
	while(y1 != y):
		if(last == 1):
			y1 += n
			last = 2
			s += "N"
		else:
			y1 -= n
			last = 1
			s += "S"
		n += 1
		
	return s

m = [[0, 1], [0, -1], [1, 0], [-1, 0]]
T = input()

for i in range(T):
	line = raw_input().split(" ")
	print "Case #" + str(i + 1) + ": " + str(solve(int(line[0]), int(line[1])))
