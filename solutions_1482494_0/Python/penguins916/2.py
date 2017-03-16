import math
from math import log

f = open('input.txt')
samples = int(f.readline().strip())
output = ''
for k in range(samples):
	numLevels = int(f.readline().strip())
	levels = []
	currentStars = 0
	for j in range(numLevels):
		levels.append([int(x) for x in f.readline().strip().split(' ')])

	#find 2 start
	remove2Star = []
	onestar = []
	len1star = 0;
	oldlen1star = 1;

	levelsPlayed = 0

	breakOut = False
	while len(levels) > 0 and breakOut == False:
		redo = True
		while redo:
			oldlen1star = len1star
			len1star = 0
			redo = False
			onestar = []
			for level in levels:
				if(level[1] <= currentStars):
					currentStars += 2
					levelsPlayed += 1
					redo = True
					#break
				else:
					onestar.append(level)
					len1star += 1

			levels = onestar


		#do the one star levels
		maxlevel2 = 0;
		maxindex = None;
		index = 0;
		if len(levels) == 0:
			break
		print levels
		for level in levels:
			if(level[0] <= currentStars and level[1]>maxlevel2):
				maxlevel2 = level[1]
				maxindex = index
			index += 1
		if maxindex == None:
			#print "Too Bad"
			breakOut = True
		else:
			currentStars += 1
			levelsPlayed += 1

			#swap it so that now the next one is not possible
			if levels[maxindex][1] != 5000:
				levels[maxindex][0] = levels[maxindex][1]
				levels[maxindex][1] = 5000
			else:
				levels.pop(maxindex)


	#go back to top until score is me

	output += 'Case #' + str(k+1)+': '
	if breakOut == True:
		output += "Too Bad" + '\n'
	else:
		output += str(levelsPlayed) + '\n'


o = open('output.txt', 'w')
o.write(output)
o.close
print output
