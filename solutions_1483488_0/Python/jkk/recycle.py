#!/usr/bin/env python

import sys


case_no = 0
for line in sys.stdin:
	line = [int(val) for val in line.strip().split()]
	if len(line) == 1:
		continue
	case_no += 1
	start, end = line
	seen = set()
	count = 0
	for num in xrange(start, end + 1):
		if num in seen:
			continue
		num = str(num)
		cur = 0
		found = []
		for i in xrange(len(num)):
			num = num[-1] + num[:-1]
			val = int(num)
			if val not in seen:
				if start <= val <= end:
					cur += 1
					seen.add(val)
					found.append(val)
		count += cur * (cur - 1) / 2
###		if cur > 1:
###			print found

	print "Case #%d: %d" % (case_no, count)
