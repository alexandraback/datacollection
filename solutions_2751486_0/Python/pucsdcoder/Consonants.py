#Author : Sumit Mahamuni
#email  : sumit143smailbox@gmail.com

import sys

inputfile_name = sys.argv[1]

def is_consonant(c):
	return ('aeiou'.__contains__(c) == False)

def substrings_for(name):
	substrings = []
	for i in range(0,len(name)):
		for j in range(0,i+1):
			substrings.append(name[j:i+1])
	return substrings

def has_consecutive_consonants(string, n):
	length = len(string)
	for i in range(0,length):
		if((length - i) < n):
			return False
		for j in range(0, n):
			result = is_consonant(string[i+j])
			if(result != True):
				break

		if(result):
			return result

def find_n_valued_substrings(name, n):
	substrings = filter((lambda x: ((len(x) >= n) and has_consecutive_consonants(x, n))) , substrings_for(name))
	return substrings

with open(inputfile_name) as infile:
	T = int(infile.readline())

	for case in range(0,T):
		_first_line = infile.readline()
		name, n = _first_line.split(' ')
		n = int(n)
		print "Case #%d: %d" % ((case+1), len(find_n_valued_substrings(name, n)))
		