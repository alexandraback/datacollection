#! /usr/bin/python
# -*- coding: utf-8 -*-


import codejammer # https://bitbucket.org/turion/codejammer

def reduce_word(s):
	last = ""
	for c in s:
		if c != last:
			yield c
			last = c

def double_char(word):
	return len(set(word)) < len(word)

def solve_case(case):
	words = list(map("".join, map(reduce_word, case[1].split(" "))))
	for word in words:
		if double_char(word):
			codejammer.iinput("double")
			return 0
	result = 1
	import itertools
	onechargroups = [(c, list(l)) for c, l in itertools.groupby(sorted(filter(lambda t: len(t[1]) == 1, enumerate(words)), key=lambda t: t[1]), key=lambda t: t[1])]
	import math
	for group in onechargroups:
		result *= math.factorial(len(group))
		codejammer.iinput(group)
	for i in reversed(sorted(i for group in onechargroups for i, word in group[1][1:])):
		del words[i]
	onechars = filter(lambda t: len(t[1]) == 1, enumerate(words))
	for i in reversed(sorted(set(i for i, char in filter(lambda t: t[1] in set([word[0] for word in words] + [word[-1] for word in words]), onechars)))):
		del words[i]
	if len(words) == 1:
		return result
	if (len(set(word[0] for word in words)) < len(words)) or (len(set(word[-1] for word in words)) < len(words)):
		for word in words:
			codejammer.debug(word)
		codejammer.iinput("mult end/beg")
		return 0
	while True:
		if any(double_char(word) for word in words):
			return 0
		by_beg = sorted(enumerate(words), key=lambda t: t[1][0])
		by_end = sorted(enumerate(words), key=lambda t: t[1][-1])
		#bind = sorted(enumerate(by_beg), key=lambda t: t[1][0])
		#eind = sorted(enumerate(by_end), key=lambda t: t[1][0])
		by_begi = iter(by_beg)
		by_endi = iter(by_end)
		try:
			i, b = next(by_begi)
			j, e = next(by_endi)
		except StopIteration:
			return result
		concats = []
		try:
			#codejammer.iinput((b, e))
			while b[0] != e[-1] or i == j:
				#codejammer.iinput((b[0], e[-1]))
				while b[0] < e[-1]:
					i, b = next(by_begi)
				#codejammer.iinput((b[0], e[-1]))
				while b[0] > e[-1]:
					j, e = next(by_endi)
		except StopIteration:
			break
		new_word = e + b[1:]
		i, j = sorted([i,j])
		if i == j:
			continue
		try:
			del words[j]
			del words[i]
		except IndexError:
			raise ValueError(i, j)
		words.append(new_word)
	import operator, functools
	bigword = functools.reduce(operator.add, words)
	codejammer.iinput((bigword, double_char(bigword)))
	if double_char(bigword):
		return 0
	result *= math.factorial(len(words))
	return result % 1000000007
test_in = """3
3
ab bbbc cd
4
aa aa bc c
2
abc bcd"""
test_solution = """Case #1: 1
Case #2: 4
Case #3: 0"""

#codejammer.set_level(codejammer.DEBUG)
#codejammer.test_jam(test_in, test_solution, solve_case, handler="double")
codejammer.jam("B", solve_case, handler="double", attempt=2)
