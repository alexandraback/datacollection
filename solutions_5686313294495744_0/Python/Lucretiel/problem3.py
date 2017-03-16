#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *

from collections import defaultdict

#code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t) gen, @trace func|gen
#   solve(int_token: int, list_token: ('int_token', str)):

class WordSet:
	def __init__(self, init=()):
		self.words = set()
		self.words_by_first_word = defaultdict(set)
		self.words_by_second_word = defaultdict(set)

		for word in init:
			self.add(word)

	def add(self, word):
		self.words.add(word)
		self.words_by_first_word[word[0]].add(word)
		self.words_by_second_word[word[1]].add(word)

	def count_first(self, word):
		return len(self.words_by_first_word[word[0]])

	def count_second(self, word):
		return len(self.words_by_second_word[word[1]])

	def __iter__(self):
		yield from self.words


@autosolve
@collects
def solve(N: int, words: ('N', (str, str))):
	all_words = WordSet(words)
	sources = WordSet()
	potential_fakes = set(words)

	for word in words:
		if all_words.count_first(word) == 1 or all_words.count_second(word) == 1:
			sources.add(word)
			potential_fakes.discard(word)

	# More seeding
	for word in sorted(words, key=lambda word: (all_words.count_first(word), all_words.count_second(word)), reverse=True):
		if sources.count_first(word) == 0 and sources.count_second(word) == 0:
			sources.add(word)
			potential_fakes.discard(word)

	# EVEN MORE SEEDING
	for word in sorted(words, key=lambda word: (all_words.count_first(word), all_words.count_second(word)), reverse=True):
		if sources.count_first(word) == 0 or sources.count_second(word) == 0:
			sources.add(word)
			potential_fakes.discard(word)

	debug(sources.words)

	# At this point all things should be equal
	return len(potential_fakes)



