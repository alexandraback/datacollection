import numpy as np
import sys

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
digitsLookup = {d:i for i,d in enumerate(digits)}
letters = sorted(list(set(list("".join(digits)))))
lettersLookup = { l:i for i,l in enumerate(letters) }

matrix = np.zeros((len(digits),len(letters)))
for i,digit in enumerate(digits):
	for l in digit:
		matrix[i,lettersLookup[l]] += 1

def getNumbers(text):

	B = np.zeros((len(letters)))
	for l in text:
		B[lettersLookup[l]] += 1

	#print B

	strategy = [("ZERO","Z"),("TWO","W"),("FOUR","U"),("SIX","X"),("EIGHT","G"),("FIVE","F"),("SEVEN","V"),("THREE","T"),("ONE","O"),("NINE","E")]

	actualNumbers = []
	for digit,letter in strategy:
		count = int(B[lettersLookup[letter]])
		digitNum = digitsLookup[digit]
		B -= count*matrix[digitNum,:]
		#print digit,count
		actualNumbers += [ digitNum for _ in xrange(count) ]

	assert np.sum(B) == 0.0

	actualNumbers = sorted(actualNumbers)
	textVersion = "".join(map(str,actualNumbers))
	return textVersion

caseCount = int(sys.stdin.readline().strip())
for i in range(caseCount):
	text = sys.stdin.readline().strip()
	result = getNumbers(text)
	print "Case #%d: %s" % (i+1,result)
