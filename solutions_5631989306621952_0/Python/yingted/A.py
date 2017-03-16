#!/usr/bin/env python
import itertools

def main():
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t,
		s = raw_input().strip()
		def dfs(p):
			if len(p) == len(s):
				return p
			c = s[len(p)]
			return max(dfs(p + c), dfs(c + p))
		print dfs('')

if __name__ == '__main__':
	main()
