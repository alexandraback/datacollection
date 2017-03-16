# Using the 3rd party library "gmpy2"
# gmpy2 is covered under the GNU LGPL license and
# can be downloaded from http://code.google.com/p/gmpy/
import gmpy2
from gmpy2 import mpz

import math
import sys

def replaceVowels(word):
	letters = []            # make an empty list to hold the non-vowels
	for char in word:       # for each character in the word
		if char.lower() not in 'aeiou':    # if the letter is not a vowel
			letters.append(char)         # add it to the list of non-vowels
		else:
			letters.append('0')
	return ''.join(letters) # join the list of non-vowels together into a string


# Read data file into a list
lines = []
with open(sys.argv[1], "r", encoding="utf-8") as data_file:
	for line in data_file:
		lines.append(line.rstrip('\n'))
		
		
# Get total number of test cases
test_cases = int(lines[0])
del lines[0]

# Process each test case
case = 0
for line in lines:
	
	case += 1
	
	name = str(line.split(" ")[0])
	n = int(line.split(" ")[1])
	length = len(name)
	
	name = replaceVowels(name)
	
	n_count = 0
	for i in range(length):
		count = 0
		for j in range(i + 1, length + 1):
			if not name[j - 1] == '0':
				count += 1
			elif count < n:
				count = 0	

			if count >= n:
				n_count += 1
				
	print("Case #" + str(case) + ": " + str(n_count))