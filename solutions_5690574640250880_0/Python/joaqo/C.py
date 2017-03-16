T = int(raw_input())
for i in range(T):
	(height, width, numMines) = [int(j) for j in raw_input().split()]
	if numMines == height*width-1:
		# only one free space. Trivial solution
		print("Case #"+`i+1`+":")
		printable = "c"
		for j in range(width-1):
			printable += "*"
		print(printable)
		printable = ""
		for j in range(width):
			printable += "*"
		for k in range(height-1):
			print(printable)
		continue
	elif height==1:
		if numMines>=width:
			print("Case #"+`i+1`+":")
			print("Impossible")
			continue
		else:
			print("Case #"+`i+1`+":")
			printable = "c"
			for j in range(width-numMines-1):
				printable += "."
			for j in range(numMines):
				printable += "*"
			print(printable)
			continue
	elif width==1:
		if numMines>=height:
			print("Case #"+`i+1`+":")
			print("Impossible")
			continue
		else:
			print("Case #"+`i+1`+":")
			print("c")
			for j in range(height-numMines-1):
				print(".")
			for j in range(numMines):
				print("*")
			continue
	elif numMines<=(width-2)*(height-2):
		#lower right rectangle
		print("Case #"+`i+1`+":")
		printable = ""
		for j in range(width-2):
			printable += "."
		print("c."+printable)
		print(".."+printable)
		blankSpacesMissing = (width-2)*(height-2)-numMines
		for k in range(height-2):
			printable = ""
			for j in range(width-2):
				if blankSpacesMissing>0:
					printable += "."
					blankSpacesMissing -= 1
				else:
					printable += "*"
			print(".."+printable)
	elif 4>width*height-numMines or 5==width*height-numMines or 7==width*height-numMines:
		print("Case #"+`i+1`+":")
		print("Impossible")
	elif width==2:
		if width*height-numMines<4 or numMines%2==1:
			print("Case #"+`i+1`+":")
			print("Impossible")
		else:
			print("Case #"+`i+1`+":")
			print("c.")
			print("..")
			for j in range((height-2)-numMines/2):
				print("..")
			for j in range(numMines/2):
				print("**")
	elif height==2:
		if width*height-numMines<4 or numMines%2==1:
			print("Case #"+`i+1`+":")
			print("Impossible")
		else:
			print("Case #"+`i+1`+":")
			printableLine1 = "c."
			printableLine2 = ".."
			for j in range((width-2)-numMines/2):
				printableLine1 += "."
				printableLine2 += "."
			for j in range(numMines/2):
				printableLine1 += "*"
				printableLine2 += "*"
			print(printableLine1)
			print(printableLine2)
	elif (width*height-numMines)%2 == 0:
		print("Case #"+`i+1`+":")
		blankSpacesMissing = width*height-numMines
		printableLine1 = "c."
		printableLine2 = ".."
		blankSpacesMissing -= 4
		for j in range(width-2):
			if blankSpacesMissing>0:
				printableLine1 += "."
				printableLine2 += "."
				blankSpacesMissing -= 2
			else:
				printableLine1 += "*"
				printableLine2 += "*"
		print(printableLine1)
		print(printableLine2)
		printableRight = ""
		for j in range(width-2):
			printableRight += "*"
		for j in range(height-2):
			if blankSpacesMissing>0:
				print(".."+printableRight)
				blankSpacesMissing -= 2
			else:
				print("**"+printableRight)
	elif (width*height-numMines)%2 == 1:
		print("Case #"+`i+1`+":")
		blankSpacesMissing = width*height-numMines
		printableLine1 = "..."
		printableLine2 = ".c."
		printableLine3 = "..."
		blankSpacesMissing -= 9
		for j in range(width-3):
			if blankSpacesMissing>0:
				printableLine1 += "."
				printableLine2 += "."
				printableLine3 += "*"
				blankSpacesMissing -= 2
			else:
				printableLine1 += "*"
				printableLine2 += "*"
				printableLine3 += "*"
		print(printableLine1)
		print(printableLine2)
		print(printableLine3)
		printableRight = ""
		for j in range(width-2):
			printableRight += "*"
		for j in range(height-3):
			if blankSpacesMissing>0:
				print(".."+printableRight)
				blankSpacesMissing -= 2
			else:
				print("**"+printableRight)
	else:
		#this branch should be unreachable
		print("Case #"+`i+1`+": Meh")