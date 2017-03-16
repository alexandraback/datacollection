from __future__ import division
from collections import defaultdict

fin = open('B-small-attempt2.in', 'r')
fout = open('B.out', 'w')

cases = int(fin.readline().rstrip('\n'))
# print cases

# d = defaultdict(int)
# print 'a' in d
# a = 'aula'
# print a[-1:]
def factorial(n):
	f = 1
	for i in xrange(1, n+1):
		f *= i
	return f

def possible(keyboard, target):
	keys = defaultdict(int)
	for letter in keyboard:
		keys[letter] += 1

	for letter in target:
		if letter not in keys:
			return False
	return keys

def overlap(target):
	m = 0
	for i in xrange(1, len(target)):
		# print target[:i], target[-i:]
		if target[:i] == target[-i:]:
			m = i
	return m

def probability(target, keys, k):
	letters = defaultdict(int)
	p = 1
	for letter in target:
		letters[letter] += 1
		p *= keys[letter]/k
	# print p
	# print letters
	# for letter in letters:
	# 	p /= factorial(letters[letter])
	# print p
	return p

for case in xrange(1, cases+1):
	answer = 'Case #' + str(case) + ': '
	# print case
	k, l, s = [int(i) for i in fin.readline().rstrip('\n').split()]
	keyboard = fin.readline().rstrip('\n')
	target = fin.readline().rstrip('\n')

	keys = possible(keyboard, target)
	if keys:
		# print 'possible'
		overlap_size = overlap(target)
		# print overlap_size
		max_bananas = 1 + (s-l)//(l-overlap_size)
		# print max_bananas
		# print probability(target, keys, k)
		answer += str(max_bananas*(1-probability(target, keys, k)))
	else:
		answer += '0.0'

	print answer
	fout.write(answer+'\n')

fin.close()
fout.close()