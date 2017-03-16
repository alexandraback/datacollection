import sys

f = open(sys.argv[1], "r")

n = int(f.readline().strip())
for t in range(1, n + 1):
	lines = []
	for row in range(4):
		lines.append(f.readline().strip())
	f.readline()
		
	for col in range(4):
		lines.append(lines[0][col] + lines[1][col] + lines[2][col] + lines[3][col])
		
	lines.append(lines[0][0] + lines[1][1] + lines[2][2] + lines[3][3])
	lines.append(lines[0][3] + lines[1][2] + lines[2][1] + lines[3][0])
	
	empty = 0
	won = False
	for line in lines:
		empty += line.count(".")
		if line.count("O") + line.count("T") == 4:
			print "Case #%d: O won" % t
			won = True
			break
		if line.count("X") + line.count("T") == 4:
			print "Case #%d: X won" % t
			won = True
			break
		
	if not won:
		if empty == 0:
			print "Case #%d: Draw" % t
		else:
			print "Case #%d: Game has not completed" %t
	
f.close()