#!/usr/bin/env python
import itertools
import sys
sys.setrecursionlimit(10000)

def solve(s):
	if s == '':
		return ''
	p = solve(s[:-1])
	c = s[-1]
	return max(p + c, c + p)

def brute_force(s):
	def dfs(i):
		if len(p) == len(s):
			return p
		c = s[len(p)]
		return max(dfs(p + c), dfs(c + p))
	return dfs('')

def main():
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t,
		s = raw_input().strip()
		print solve(s)

if __name__ == '__main__':
	main()
