#!/usr/bin/python

T = input()
for t in range(1, T + 1):
	S = raw_input()

	pan = []
	for c in S:
		if c == '+':
			pan.append(1)
		else:
			pan.append(-1)
#print pan

	result = 0
	while pan != [1] * len(S):
		result += 1
		rindex = len(S)
		baseSide = pan[0]
		for index, cake in enumerate(pan):
#print "index, cake ", index, cake
			if cake != baseSide:
				rindex = index
				break
		for i in range(rindex / 2):
#print "i, rindex - i ", i, rindex - i
			pan[i], pan[rindex - i - 1] = -pan[rindex - i - 1], -pan[i]
		if rindex % 2 != 0:
		 	pan[rindex / 2] *= -1
#print pan

	print "Case #%d: %s" % (t, result)
