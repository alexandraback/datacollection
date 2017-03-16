import sys
import string
import math
file = sys.argv[1]

lines = open(file).readlines()
N = int(lines[0])

currentLine = 1

for case in range(N):
	number = int(lines[currentLine])
	currentLine = currentLine + 1
	strings = lines[currentLine].split()
	currentLine = currentLine + 1
	total = 1
	caseDone = False
	for letter in string.lowercase:
		newStrings = []
		startsWith = []
		endsWith = []
		onlyContains = []
		middle = []
		for aString in strings:
			if letter in aString:
				for aLetter in aString:
					if aLetter != letter:
						break
				else:
					onlyContains.append(aString)
					continue
				if aString[0] == letter and aString[-1] == letter:
					#impossible
					print "Case #{}: 0".format(case + 1  )
					caseDone = True
					break
				if aString[0] == letter:
					startsWith.append(aString)
				elif aString[-1] == letter:
					endsWith.append(aString)
				else:
					middle.append(aString)
			else:
				newStrings.append(aString)
		else:
			#print "total {} letter {} Start {}, middle {}, end {}, only {}".format(total,letter, startsWith, middle, endsWith, onlyContains)
			if len(middle) >= 1:
				if len(startsWith) > 0 or len(endsWith) > 0 or len(onlyContains) > 0:
					#impossible
					print "Case #{}: 0".format(case + 1  )
					caseDone = True
					break
			elif len(startsWith) > 1 or len(endsWith) > 1:
				#impossible
				print "Case #{}: 0".format(case + 1  )
				caseDone = True
				break
			else:
				total = total * math.factorial(len(onlyContains)) % 1000000007
				newStrings.append("".join(endsWith + onlyContains + startsWith))
			strings = newStrings
	else:
		newStringsCount = 0
		for aString in strings:
			if len(aString) > 0:
				newStringsCount += 1
		total = total * math.factorial(newStringsCount) % 1000000007
		if not caseDone:
			print "Case #{}: {}".format(case + 1, total  )


	