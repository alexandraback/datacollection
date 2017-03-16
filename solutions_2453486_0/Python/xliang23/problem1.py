import sys
import linecache

# put file into memory
# it's a small file, so f*ck you if you don't like it
# Put file into memory
linecache.getline(sys.argv[1], 1)

	
# Let's start checking out the data now ;)
for i in range(0, int(linecache.getline(sys.argv[1], 1))):
	
	line1 = linecache.getline(sys.argv[1], 5 * i + 2).strip()
	line2 = linecache.getline(sys.argv[1], 5 * i + 3).strip()
	line3 = linecache.getline(sys.argv[1], 5 * i + 4).strip()
	line4 = linecache.getline(sys.argv[1], 5 * i + 5).strip()
	column1 = line1[0] + line2[0] + line3[0] + line4[0]
	column2 = line1[1] + line2[1] + line3[1] + line4[1]
	column3 = line1[2] + line2[2] + line3[2] + line4[2]
	column4 = line1[3] + line2[3] + line3[3] + line4[3]
	diag1 = line1[0] + line2[1] + line3[2] + line4[3]
	diag2 = line1[3] + line2[2] + line3[1] + line4[0]
	
	game_end = 0 
	list_checks = [line1, line2, line3, line4, column1, column2, column3, column4, diag1, diag2]
	list_lines = [line1, line2, line3, line4]
	
	#for seq4 in list_checks:
	#	print seq4
	#sys.exit(1)
	
	# Check X
	for seq4 in list_checks:
		if game_end == 0:
			crap = 0
			for char in seq4:
				if char == "X" or char == "T":
					crap += 1
				if crap == 4:
					print "Case #%d: X won" % (i+1)
					game_end = 1
				
	# Check O
	if game_end == 0:
		for seq4 in list_checks:
			if game_end == 0:
				crap = 0
				for char in seq4:
					if char == "O" or char == "T":
						crap += 1
					if crap == 4:
						print "Case #%d: O won" % (i+1)
						game_end = 1	
					
	# Check if game is unfinished
	if game_end == 0:
		for line in list_lines:
			if "." in line:
				print "Case #%d: Game has not completed" % (i+1)
				game_end = 1
				break
			
	# else the game is a draw
	if game_end == 0:
		print "Case #%d: Draw" % (i+1)
			
	
			
	

	
	
