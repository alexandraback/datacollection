#!/usr/bin/env python
def main():
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t,
		d = int(raw_input())
		a = map(int, raw_input().split())
		best = max(a)
		for limit in xrange(1, max(a) + 1):
			cost = 0
			for x in a:
				cost += (x - 1) / limit
			best = min(best, limit + cost)
		print best
if __name__ == '__main__':
	main()
