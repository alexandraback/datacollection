#! /usr/bin/python
# -*- coding: utf-8 -*-

import codejammer # https://bitbucket.org/turion/codejammer
#codejammer.set_level(codejammer.DEBUG)

vowels = "aeiou"
def has_n_ss(n, string):
	codejammer.debug(("canihaz", n, string))
	for i in range(len(string)-n+1):
		codejammer.debug(("looking for", i, i+n, string[i:i+n]))
		if all([letter not in vowels for letter in string[i:i+n]]):
			codejammer.debug("yes")
			return True
	else:
		codejammer.debug("no")
		return False

def has_n_ss_old(n, string):
	#codejammer.debug(("canihaz", n, string))
	i = 0
	while True:
		try:
			while string[i] in vowels:
				i += 1
		except IndexError:
			break
		if i+n >= len(string):
			break
		codejammer.debug(("looking for", i, i+n, string[i:i+n]))
		if all([letter not in vowels for letter in string[i:i+n]]):
			codejammer.debug("yes")
			return True
		else:
			i += 1
	return False

def n_value(case):
	string, n = case.split()
	n = int(n)
	value = 0
	for i in range(len(string)):
		for j in range(i+1, len(string)+1):
			if has_n_ss(n, string[i:j]):
				value += 1
	return value


test_in = """4
quartz 3
straight 3
gcj 2
tsetse 2"""

test_solution = """Case #1: 4
Case #2: 11
Case #3: 3
Case #4: 11"""

codejammer.test_jam(test_in, test_solution, n_value)
codejammer.jam("A", n_value)
