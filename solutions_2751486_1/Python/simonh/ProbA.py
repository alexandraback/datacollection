'''
Created on 12/05/2013

@author: shb
'''
import sys

vowels = set(['a', 'e', 'i', 'o', 'u'])

def mark_substrings(name):
	substrings = []
	current_start = 0
	in_substring = False
	for i, c in enumerate(name):
		if c not in vowels:
			if not in_substring:
				current_start = i
				in_substring = True
		else:
			if in_substring:
				substrings.append((current_start, i))
				current_start = 0
				in_substring = False
	if in_substring:
		substrings.append((current_start, i + 1))
	return substrings

def split_substrings(substrings, maxlen):
	actual_substrings = []
	for s in substrings:
		for start in range(s[0], s[1] - maxlen + 1):
			actual_substrings.append((start, start + maxlen))
	return actual_substrings
	
def count_owned_substrings(earliest_start, substring, word_length):
	return (substring[0] - earliest_start) * (word_length - substring[1] + 1)

if __name__ == '__main__':
	T = int(sys.stdin.readline())
	for i in range(T):
		name, n = sys.stdin.readline().split()
		n = int(n)
		substrings = mark_substrings(name)
		relevant_substrings = []
		for a, b in substrings:
			if b - a >= n:
				relevant_substrings.append((a, b))
		
		# for a, b in relevant_substrings:
		# 	print name[a:b]
		actual_substrings = split_substrings(relevant_substrings, n)
		# for a, b in actual_substrings:
		# 	print name[a:b]
			
		n_value = 0
		for ss1, ss2 in zip(actual_substrings, actual_substrings[1:]):
			n_value += count_owned_substrings(ss1[0], ss2, len(name))
		# remember the leading substrings
		try:
			ss = actual_substrings[0]
			n_value += (ss[0] + 1) * (len(name) - ss[1] + 1)
		except IndexError:
			pass # something weird
		print 'Case #{}: {}'.format(i+1, n_value)

