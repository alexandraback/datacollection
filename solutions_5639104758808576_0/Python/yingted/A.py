#!/usr/bin/env python
def main():
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t,
		_, s = raw_input().split()
		s = s.rstrip('0')
		standing = 0
		added = 0
		for si, c in enumerate(map(int, s)):
			if standing < si:
				invite = si - standing
				added += invite
				standing += invite
			standing += c
		print added
if __name__ == '__main__':
	main()
