#!/usr/bin/python

import string

vowels = 'aeiou'

def maxConsecutiveConsonants(word):
	counter = 0
	maxCounter = 0

#	print 'consecutive consonants:', word,
	for letter in word:
		if letter not in vowels:
			counter += 1
		else:
			if counter > maxCounter:
				maxCounter = counter
			counter = 0
				
	if counter > maxCounter:
		maxCounter = counter
		
#	print maxCounter

	return maxCounter
	
def generateSubstring(word):
	for i in range(len(word)):
		for j in range(i, len(word) + 1):
			if i != j:
#				print i, j, word[i:j], maxConsecutiveConsonants(word[i:j])
				yield word[i:j]

def countSubstrings(word, n):
	counter = 0

	for substring in generateSubstring(word):
		consecutiveConsonants = maxConsecutiveConsonants(substring)
		if consecutiveConsonants >= n:
	#		print substring
			counter += 1
		
	return counter


# Open file
fp = open('A-small-attempt0.in')
#fp = open('data.txt')
cases = int(fp.readline())
print '#Cases:', cases

# Open output file
fpout = open('output.txt', 'w')

for i in range(cases):
	[word, n] = [data for data in fp.readline().split()]
		
	counter = countSubstrings(word, int(n))
		
	print 'Case #%d: %d' %(i + 1, counter)
	fpout.write('Case #%d: %d\n' %(i + 1, counter))