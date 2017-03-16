#MAM, Google Code Jam - 2016 Round 1B, Problem 2
#Close Match

zeroToNine = "01234567890123456789"

def changeStr(myS, pos, ch):
	myList = list(myS)
	myList[pos] = ch
	return ''.join(myList)

def fillChar(sA, sB, pos):

	answers = []

	#print sA, sB, pos

	charA = sA[pos]
	charB = sB[pos]

	#print "chara/b ", charA, charB

	knownA = True
	knownB = True

	if charA == '?': knownA = False
	if charB == '?': knownB = False

	if knownA and knownB:
		answers.append([sA, sB])
		return answers

	# nothing filled, A ?? B
	if pos == 0:
		if not knownA and knownB:
			intB = int(charB)
			copyA = sA+""
			
			copyA = changeStr(copyA, pos, zeroToNine[intB-1])
			answers.append([copyA, sB])
			
			copyA = changeStr(copyA, pos, zeroToNine[intB])
			answers.append([copyA, sB])
			
			copyA = changeStr(copyA, pos, zeroToNine[intB+1])
			answers.append([copyA, sB])

			return answers

		if knownA and not knownB:
			intA = int(charA)
			copyB = sB+""

			copyB = changeStr(copyB, pos, zeroToNine[intA-1])
			answers.append([sA, copyB])

			copyB = changeStr(copyB, pos, zeroToNine[intA])
			answers.append([sA, copyB])

			copyB = changeStr(copyB, pos, zeroToNine[intA+1])
			answers.append([sA, copyB])

			return answers

		if not knownA and not knownB:

			copyA = sA+""
			copyB = sB+""
			copyA = changeStr(copyA, pos, '0')
			copyB = changeStr(copyB, pos, '0')
			answers.append([copyA, copyB])

			copyA = changeStr(copyA, pos, '1')
			copyB = changeStr(copyB, pos, '0')
			answers.append([copyA, copyB])

			copyA = changeStr(copyA, pos, '0')
			copyB = changeStr(copyB, pos, '1')
			answers.append([copyA, copyB])

			return answers

	#At least one filled, compare A to B

	myA = int(sA[:pos])
	myB = int(sB[:pos])

	if myA == myB:
		if not knownA and knownB:
			intB = int(charB)
			copyA = sA+""
			
			copyA = changeStr(copyA, pos, zeroToNine[intB-1])
			answers.append([copyA, sB])
			
			copyA = changeStr(copyA, pos, zeroToNine[intB])
			answers.append([copyA, sB])
			
			copyA = changeStr(copyA, pos, zeroToNine[intB+1])
			answers.append([copyA, sB])

			return answers

		if knownA and not knownB:
			intA = int(charA)
			copyB = sB+""

			copyB = changeStr(copyB, pos, zeroToNine[intA-1])
			answers.append([sA, copyB])

			copyB = changeStr(copyB, pos, zeroToNine[intA])
			answers.append([sA, copyB])

			copyB = changeStr(copyB, pos, zeroToNine[intA+1])
			answers.append([sA, copyB])

			return answers

		if not knownA and not knownB:

			copyA = sA+""
			copyB = sB+""


			copyA = changeStr(copyA, pos, '0')
			copyB = changeStr(copyB, pos, '9')
			answers.append([copyA, copyB])

			copyA = changeStr(copyA, pos, '9')
			copyB = changeStr(copyB, pos, '0')
			answers.append([copyA, copyB])

			copyA = changeStr(copyA, pos, '0')
			copyB = changeStr(copyB, pos, '1')
			answers.append([copyA, copyB])

			copyA = changeStr(copyA, pos, '1')
			copyB = changeStr(copyB, pos, '0')
			answers.append([copyA, copyB])

			copyA = changeStr(copyA, pos, '0')
			copyB = changeStr(copyB, pos, '0')
			answers.append([copyA, copyB])
			
			return answers


	if myA < myB:
		if not knownA and knownB:
			copyA = sA+""
			copyA = changeStr(copyA, pos, '9')
			answers.append([copyA, sB])
			return answers

		if knownA and not knownB:
			copyB = sB+""
			copyB = changeStr(copyB, pos, '0')
			answers.append([sA, copyB])
			return answers

		if not knownA and not knownB:

			copyA = sA+""
			copyB = sB+""

			copyA = changeStr(copyA, pos, '9')
			copyB = changeStr(copyB, pos, '0')
			answers.append([copyA, copyB])
			return answers

	if myA > myB:
		if not knownA and knownB:
			copyA = sA+""
			copyA = changeStr(copyA, pos, '0')
			answers.append([copyA, sB])
			return answers

		if knownA and not knownB:
			copyB = sB+""
			copyB = changeStr(copyB, pos, '9')
			answers.append([sA, copyB])
			return answers

		if not knownA and not knownB:

			copyA = sA+""
			copyB = sB+""

			copyA = changeStr(copyA, pos, '0')
			copyB = changeStr(copyB, pos, '9')
			answers.append([copyA, copyB])
			return answers

	print "fatal flaw, returning sA, SB"
	answers.append([sA, sB])
	return answers

#pos = positions filled yet
def compute(sA, sB, pos, maxPos):
	if pos == maxPos:
		return abs(int(sA)-int(sB)), sA, sB

	answer = int((maxPos) * "9")
	answerA = maxPos * "9"
	answerB = maxPos * "9"

	newTries = fillChar(sA, sB, pos)
	#print "newtries: ", newTries

	for each in newTries:
		#print "each, each0, each1", each, each[0], each[1]
		temp, tempA, tempB = compute(each[0], each[1], pos+1, maxPos)

		if temp < answer:
			answer = temp
			answerA = tempA
			answerB = tempB

		elif temp == answer:
			if int(tempA) < int(answerA):
				answerA = tempA
				answerB = tempB

			elif int(tempA) == int(answerA):
				if int(tempB) < int(answerB):
					answerB = tempB

	return answer, answerA, answerB


def solve(c):
	sA, sB = c.split(" ")
	maxPos = len(sA)

	difference, A, B = compute(sA, sB, 0, maxPos)

	answer = A + " " + B
	return answer

def main():
	with open('B-large.in', 'r') as infile, open('output.txt', 'w') as outfile:
		
		T = int(infile.readline())
		for x in xrange(T):
			line = infile.readline().rstrip()
			outfile.write("Case #" + str(x + 1) + ": " + str(solve(line)) + "\n")

if __name__ == "__main__":
	main()