import fileinput

myfile = fileinput.input();
currentcase = 0
maxcases = 0
vowels = "aeiou"

for line in myfile:
	if fileinput.isfirstline():
		maxcases = int(line.strip())
		continue

	currentcase += 1
	(name, n) = line.strip().split()

	n = int(n)
	nvalue = 0
	namecons = []
	patternlist = [1]*n
	matchcount = 0

	for letter in name:
		try:
			vowels.index(letter)
			namecons.append(0)
		except ValueError:
			namecons.append(1)

	patternmatches = [i for i in xrange(len(namecons)) if namecons[i:i+n] == patternlist]

	for k in range(len(namecons)):
		for j in range(k+1, len(namecons)+1):
			for match in patternmatches:
				if (k <= match) and (j >= match+n):
					matchcount += 1
					break
				# print str(k) + ":" + str(j) + " " + name[k:j] + " " + str(matchcount)

	print "Case #"+str(currentcase)+": "+str(matchcount)

	if maxcases == currentcase:
		break