#!/usr/bin/env python3

def memoized(func):
	func.memo = {}
	def f(arg):
		if arg not in func.memo:
			func.memo[arg] = func(arg)
		return func.memo[arg]
	return f

@memoized
def solve(cakes):
	if len(cakes) == 0:
		return (0, 'Stop.')
	
	score, reason = solve(tuple(x-1 for x in cakes if x-1 != 0))
	score += 1
	reason = 'Eat, ' + reason
	if score == 1:
		return score, reason
	
	for a in range(1, cakes[-1]):
		newscore, newreason = solve(tuple(sorted(list(cakes[:-1]) + [a, cakes[-1]-a])))
		newscore += 1
		newreason = ('Split %d into %d %d, ' % (cakes[-1], a, cakes[-1] - a)) + newreason
		if newscore < score:
			score, reason = newscore, newreason
	
	return score, reason

def doprob(p):
	input()
	cakes = tuple(sorted(int(x) for x in input().split()))
	#if p: print(cakes)
	return solve(cakes)[0]

ncases = int(input())
for caseno in range(1, ncases+1):
	answer = doprob(caseno in (18, 51, 66, 69, 93))
	#if caseno in (18, 51, 66, 69, 93):
	print('Case #%d:' % caseno, answer)