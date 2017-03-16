#!/usr/bin/python
fin = open('A-large.in')
T = int(fin.readline())
for ii in range(T):
	S = fin.readline().strip()
	result = S[0]
	for ch in S[1:]:
		if ch >= result[0]:
			result = ch + result
		else:
			result = result + ch

	print "Case #%s: %s" % (ii + 1, result)
fin.close()