#!python
# -*- coding: utf-8 -*-

import sys

Num = int(sys.stdin.readline().strip())

for index in range(Num):
	Map = [sys.stdin.readline() for x in range(4)]
	
	won = False
	for i in range(4):
		if len([Map[i][j] for j in range(4) if Map[i][j] in "OT"]) == 4:
			won = "O"
		if len([Map[j][i] for j in range(4) if Map[j][i] in "OT"]) == 4:
			won = "O"
		if len([Map[i][j] for j in range(4) if Map[i][j] in "XT"]) == 4:
			won = "X"
		if len([Map[j][i] for j in range(4) if Map[j][i] in "XT"]) == 4:
			won = "X"
	
	if len([Map[j][j] for j in range(4) if Map[j][j] in "OT"]) == 4:
		won = "O"
	if len([Map[j][j] for j in range(4) if Map[j][j] in "XT"]) == 4:
		won = "X"
	if len([Map[j][3 - j] for j in range(4) if Map[j][3 - j] in "OT"]) == 4:
		won = "O"
	if len([Map[j][3 - j] for j in range(4) if Map[j][3 - j] in "XT"]) == 4:
		won = "X"
	
	if won:
		print "Case #%d: %s won" % (index + 1, won)
	else:
		if True in ["." in line for line in Map]:
			print "Case #%d: Game has not completed" % (index + 1)
		else:
			print "Case #%d: Draw" % (index + 1)
	
	sys.stdin.readline()