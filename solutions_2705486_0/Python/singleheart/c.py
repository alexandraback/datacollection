#!/usr/bin/python

# C

import sys
import math

dic = {}

ret = []

def count(start, prev, s):
	if start >= len(s):
		return 0
	if ret[start] >= 0:
		return ret[start]

	if s[start:] in dic:
		ret[start] = 0
		return 0
	if start - prev >= 5:
		for c in 'abcdefghijklmnopqrstuvwxyz':
			if c+s[start+1:] in dic:
				if c != s[start]:
					ret[start] = 1
					return 1

#	ret[start] = 987654321
	if s[start] == 'a' or s[start] == 'i':
		ret[start] = count(start+1, prev, s)
	else:
		ret[start] = 1 + count(start+1, prev, s)

	for i in range(11, max(2, prev+5-start)-1, -1):
		for c in 'abcdefghijklmnopqrstuvwxyz':
			if (c+s[start+1:start+i]) in dic:
				if c == s[start]:
					ret[start] = min(ret[start], count(start+i, prev, s))
				else:
					ret[start] = min(ret[start], 1 + count(start+i, start, s))

	return ret[start]


f = open('garbled_email_dictionary.txt')
for l in f.readlines():
	dic[l.strip()] = l.strip()

f = sys.stdin
T = int(f.readline())

for case in range(1, T+1) :
	s = f.readline().strip()

	ret = [-1 for i in range(len(s))]
	'''
	for i in range(2, max(5, len(s)) + 1):
		if s[-i:] in dic:
			ret[-i] = 0
		for c in 'abcdefghijklmnopqrstuvwxyz':
			if c+s[-i+1:] in dic:
				if c == s[-i]:
					ret[-i] = 0
				else:
					ret[-i] = 1
		'''

	ret[0] = count(0, -10, s)

	print "Case #%d: %d" % (case, ret[0])
