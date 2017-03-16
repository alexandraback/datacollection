# python2
import fileinput
import sys

n = int(sys.stdin.readline())

for i in range (1, n + 1):
	board = [0 for x in xrange(4)]
	empty = 0
	
	for j in range (0, 4):
		columnString = sys.stdin.readline().rstrip("\n")
		if "." in columnString:
			empty = 1;
		
		columns = list(columnString)
		board[j] = columns
		
	index = 0;
	
	for j in range (0,4):
		while (index < 4 and (board[j][index] == "X" or board[j][index] == "T")) :
			index = index + 1
				
		if index == 4 :
			print "Case #" + str(i) + ": X won"
			break

		index = 0
		while (index < 4 and (board[j][index] == "O" or board[j][index] == "T")) :
			index = index + 1

		if index == 4:
			print "Case #" + str(i) + ": O won"
			break

		index = 0
		while (index < 4 and (board[index][j] == "X" or board[index][j] == "T")) :
			index = index + 1
		
		if index == 4:
			print "Case #" + str(i) + ": X won"
			break

		index = 0
		while (index < 4 and (board[index][j] == "O" or board[index][j] == "T")) :
			index = index + 1
		
		if index == 4:
			print "Case #" + str(i) + ": O won"
			break

	if index != 4:
		index = 0;
		while (index < 4 and (board[index][index] == "X" or board[index][index] == "T")) :
			index = index + 1
		
		if index == 4:
			print "Case #" + str(i) + ": X won"
	
	if index != 4:
		index = 0
		while (index < 4 and (board[index][index] == "O" or board[index][index] == "T")) :
			index = index + 1
		
		if index == 4:
			print "Case #" + str(i) + ": O won"

	if index != 4:
		index = 0

		while (index < 4 and (board[3 - index][index] == "X" or board[3 - index][index] == "T")) :
			index = index + 1
		
		if index == 4:
			print "Case #" + str(i) + ": X won"

	if index != 4:
		index = 0

		while (index < 4 and (board[3 - index][index] == "O" or board[3 - index][index] == "T")) :
			index = index + 1
		
		if index == 4:
			print "Case #" + str(i) + ": O won"
	
	if index != 4:
		if empty == 1:
				print "Case #" + str(i) + ": Game has not completed"
		else:
				print "Case #" + str(i) + ": Draw"
	
	empty = sys.stdin.readline().rstrip("\n")