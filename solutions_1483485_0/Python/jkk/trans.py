#!/usr/bin/env python

import sys

sys.stdin.readline()

case_no = 1
for line in sys.stdin:
	line = line.strip()
	trans = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'q': 'z', 'z': 'q'}

	ans = ''
	for char in line:
		ans += trans[char]
	
	# handle q and z...
	print "Case #%d: %s" % (case_no, ans)
	case_no += 1
