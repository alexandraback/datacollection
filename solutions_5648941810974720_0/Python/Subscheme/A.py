from sys import setrecursionlimit as slr
from collections import Counter
slr(10**9)

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache: cache[args] = f(*args)
		return cache[args]
	return wrap

getl = lambda: raw_input().strip().split()
get = lambda: map(int, getl())

def put(caseNumber, result):
	print "Case #%d: %s" % (caseNumber, result)

nums = [
	'ZERO',
	'ONE',
	'TWO',
	'THREE',
	'FOUR',
	'FIVE',
	'SIX',
	'SEVEN',
	'EIGHT',
	'NINE',
]

left = [
	'FIVE',
	'SEVEN',
	'NINE'
]

chars = set(''.join(nums))

def remove(counts, i, amount):
	for c in nums[i]:
		counts[c] -= amount

def solve(s):
	letterCounts = Counter(s)

	n0 = letterCounts['Z']
	remove(letterCounts, 0, n0)

	n6 = letterCounts['X']
	remove(letterCounts, 6, n6)

	n4 = letterCounts['U']
	remove(letterCounts, 4, n4)

	n8 = letterCounts['G']
	remove(letterCounts, 8, n8)

	n3 = letterCounts['R']
	remove(letterCounts, 3, n3)

	n2 = letterCounts['W']
	remove(letterCounts, 2, n2)

	n1 = letterCounts['O']
	remove(letterCounts, 1, n1)

	n5 = letterCounts['F']
	remove(letterCounts, 5, n5)

	n7 = letterCounts['V']
	remove(letterCounts, 7, n7)

	n9 = letterCounts['I']
	remove(letterCounts, 9, n9)

	assert not any(letterCounts.values())

	return '0' * n0 + '1' * n1 + '2' * n2 + '3' * n3 + '4' * n4 + '5' * n5 + '6' * n6 + '7' * n7 + '8' * n8 + '9' * n9

T, = get()
for caseNumber in range(1, T+1):
	put(caseNumber, solve(*getl()))
