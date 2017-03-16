import string
import sys

first = {}
second = {}
words = []
def solve():
	global first
	global second
	global words

	

	count = 0
	unique_first = set()
	unique_second = set()
	for word1, word2 in words:
		if first[word1] == 1 or second[word2] == 1:
			unique_first.add(word1)
			unique_second.add(word2)
		else:
			count += 1
	for word1, word2 in words:
		if first[word1] > 1 and second[word2] > 1:
			if word1 not in unique_first and word2 not in unique_second:
				count -= 1
				unique_first.add(word1)
				unique_second.add(word2)
	for word1, word2 in words:
		if first[word1] > 1 and second[word2] > 1:
			if word1 not in unique_first:
				count -= 1
				unique_first.add(word1)
			if word2 not in unique_second:
				count -= 1
				unique_second.add(word2)

	return count

def parse(new_words):
	global first
	global second
	global words

	words.append(new_words.split())
	if words[-1][0] not in first:
		first[words[-1][0]] = 0
	first[words[-1][0]] += 1
	if words[-1][1] not in second:
		second[words[-1][1]] = 0
	second[words[-1][1]] += 1

T = int(raw_input())
for t in range(1, T+1):
	first = {}
	second = {}
	words = []
	N = int(raw_input())
	for i in range(N):
		parse(raw_input())
	print "Case #%d: %d" % (t, solve())
