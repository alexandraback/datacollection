inputData = open("B.in", "r")
outputData = open("B.out", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))


def buildWord (ss, letters, leng):
	outp = []
	for l in letters:
		if (len(ss) + 1 == leng):
			outp.append(ss + l)
		else:
			outp += buildWord(ss + l, letters, leng)
	return outp

def countOccurrences (string, sub):
	count = start = 0
	while True:
		start = string.find(sub, start) + 1
		if start > 0:
			count += 1
		else:
			return count

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if number % 3 == 0:
		(K, L, S) = map(int, line.split(" "))
		continue
	if number % 3 == 1:
		keys = line
		continue
	if number % 3 == 2:
		word = line
		for char in word:
			if char not in keys:
				case(number // 3 + 1, 0.0)
				break
		else:
			overlap = len(word)
			for i in range(1, len(word)):
				if word[i:] == word[:-i]:
					overlap = i
					break
			if S >= len(word):
				bringBananas = 1 + (S - len(word)) // overlap
			else:
				case(number // 3 + 1, 0.0)
				break
			occ = 0.0
			wrs = buildWord("", keys, S)
			# print(wrs)
			for wr in wrs:
				occ += countOccurrences(wr, word)
			# print(occ, word, len(wrs), bringBananas, countOccurrences("AAAA", "AAAA"))
			occ /= len(wrs)
			case(number // 3 + 1, bringBananas - occ)

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()