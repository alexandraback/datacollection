import itertools

def contain(bases, curSet, wordLst):
	for e in wordLst:
		if not (e in bases or e in curSet):
			return False
	return True

# iter through base of size startingGroupSz
def determ(startingGroupSz, wordLst):

	for bases in itertools.combinations(wordLst, startingGroupSz):
		curSet = set([])
		for i in xrange(len(bases)):
			base1 = bases[i]
			for j in xrange(i+1, len(bases)):
				base2 = bases[j]
				# print base1, base2
				toAdd = (base1[0], base2[1])
				curSet.add(toAdd)
				toAdd = (base2[0], base1[1])
				curSet.add(toAdd)
		# print "bases: ", bases
		# print "curSet", curSet
		if contain(bases, curSet, wordLst):
			return True

	return False


def calculate(wordLst):
	ret = 0
	leng = len(wordLst)
	if leng <= 2:
		return 0

	for startingGroupSz in range(2, leng):
		if determ(startingGroupSz, wordLst):
			ret = leng - startingGroupSz
			return ret

	return ret

def main():
    inpfile = open("C-small-attempt0.in", 'r')
    outfile = open('outputC_s.txt', 'w')
    casenum = int(inpfile.readline().strip())
    for case in range(1, casenum + 1):
        line = inpfile.readline().strip()
        lineNum = int(line)
        wordLst = set([])
        for idx in range(lineNum):
        	line = inpfile.readline().strip().split()
        	wordLst.add((line[0], line[1]))
        # print wordLst
        ret = calculate(wordLst)
        result = "Case #" + str(case) + ": " + str(ret) + "\n"
        print result
        outfile.write(result)
    inpfile.close()
    outfile.close()



if __name__ == "__main__":
	main()
	

