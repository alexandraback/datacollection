def canAlwaysTile(x, r, c):
	if (r * c) % x != 0:
		return False
	else:
		if x == 1:
			return True
		if x == 2:
			return True
		if x == 3:
			if r == 1 and c == 3 or r == 3 and c == 1:
				return False
			else:
				return True
		if x == 4:
			if r == 1 and c == 4 or r == 4 and c == 1:
				return False
			elif r == 2 or c == 2:
				return False
			else:
				return True
		else:
			print "out of bounds"
			return False

fin = open("D-small-attempt1.in", 'r')
fout = open("out.txt", 'w')

cases = int(fin.readline())
for case in range(cases):
	x, r, c = map(int, str.split(fin.readline()))
	if(canAlwaysTile(x, r, c)):
		ans = "GABRIEL"
	else:
		ans = "RICHARD"
	fout.write("Case #" + str(case + 1) + ": " + ans + "\n")

fin.close()
fout.close()