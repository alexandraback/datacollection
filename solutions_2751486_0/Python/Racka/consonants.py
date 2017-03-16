
INPUT_SAMPLE = 'A-sample.in.txt'
INPUT_SMALL  = 'A-small-attempt0.in.txt'
INPUT_LARGE  = 'A-large.in.txt'

INPUT = INPUT_SMALL

vowels = list("aeiou")

def noOfVowels(aWord):
	return sum(aWord.count(c) for c in vowels)

def noOfConsonants(aWord):
	return len(aWord) - noOfVowels(aWord)

def maxNoOfConsecutiveConsonants(aWord):
	maximum = 0
	currmax = 0
	for c in aWord:
		if c in vowels:
			maximum = max(maximum, currmax)
			currmax = 0
		else:
			currmax +=1
	maximum = max(maximum, currmax)
	return maximum

# 26 letters
# a,e,i,o,u - vowels
# less common name => more social privilege
# hard to pronounce => uncommon => many consecutive consonants
# value of name, n-value = no of substrings with at least n consecutive consonants
# 2 substrings are diff if the begin|end at different points




f = open("output.txt", 'w')

lines = open(INPUT, 'r').readlines()
lines = [x.rstrip('\n') for x in lines]

noTestCases = int(lines[0])
lines = lines[1:]

for currTestCase in xrange(0, noTestCases):
	if (currTestCase !=0):
		f.write("\n")

	f.write('Case #' + str(currTestCase+1) + ": ")


	#  line has name of a member, and an int n
	name = lines[0].split(' ')[0]
	n    = int(lines[0].split(' ')[1])


	# get all the substrings of length >= n
	# and then check if they have consonants
	nameLen = len(name)
	nValue = 0

	for startIdx in xrange(0, nameLen):
		for endIdx in xrange(startIdx + n, nameLen +1):

			currSubstring = name[startIdx:endIdx]



			if maxNoOfConsecutiveConsonants(currSubstring) >= n :
				# print ('doing substring ' + currSubstring)
				nValue +=1

	# write the n-value
	f.write(str(nValue))

	# trim the remaining lines for the next test case
	lines = lines[1:]

