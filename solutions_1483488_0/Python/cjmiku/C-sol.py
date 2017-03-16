#!/usr/bin/env python
# coding: utf-8

""" 
Let's say a pair of distinct positive integers (n, m) is recycled if you
can obtain m by moving some digits from the back of n to the front without
changing their order. For example, (12345, 34512) is a recycled pair since you
can obtain 34512 by moving 345 from the end of 12345 to the front. Note that n
and m must have the same number of digits (excluding leading zeros) in order
to be a recycled pair.

Given integers A and B with the same number of digits, how many distinct
recycled pairs (n, m) are there with A <= n < m <= B?
"""

import pprint

if __name__ == '__main__':
	with open('C-small-attempt0.in') as handle:
		lines = handle.readlines()
		for case_id, line in enumerate(lines[1:], start=1):
			lower, upper = map(int, line.strip().split())
			recycled = set()
			for i in range(lower, upper + 1):
				s = str(i)
				# go over all suffixes
				for j in range(1, len(s)):
					prefix, suffix = s[:j], s[j:]
					# candidate = int('%s%s' % (suffix, prefix))
					candidate = int(suffix + prefix)
					if candidate >= lower and candidate <= upper and not candidate == i:
						# candidate is actually between lower and upper
						recycled.add( tuple(sorted([candidate, i])) )
					# print('number: %s, prefix: %s, suffix %s' % (i, s[:j], s[j:]))
			print('Case #%s: %s' % (case_id, len(recycled)))
			# pprint.pprint(recycled)
