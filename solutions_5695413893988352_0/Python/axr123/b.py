import sys

def getMinMax(s):
	_min = 0
	_max = 0
	f = 1
	for c in s:
		_min *= 10
		_max *= 10
		if c == '?':
			_min += 0
			_max += 9
		else:
			_min += int(c)
			_max += int(c)
	return _min, _max

def isValid(v, l):
	if len(l) == 3: v = "%03d" % v
	elif len(l) == 2: v = "%02d" % v
	else: v = "%d" % v
	assert(len(v) == len(l))
	for i in range(len(v)):
		if l[i] != '?' and l[i] != v[i]: return False
	return True

numcases = int(sys.stdin.readline())
for _c in range(numcases):
	coders, jammers = sys.stdin.readline().split()
	cMin, cMax = getMinMax(coders)
	jMin, jMax = getMinMax(jammers)
	# print("%03d - %03d : %03d - %03d" % (cMin, cMax, jMin, jMax))
	bestDiff = 999
	bestC = 0
	bestJ = 0
	for c in range(cMin, cMax+1):
		if not isValid(c, coders): continue
		for j in range(jMin, jMax+1):
			if not isValid(j, jammers): continue
			if (abs(j-c) < bestDiff):
				bestDiff = abs(j-c)
				bestC = c
				bestJ = j
	# this is ugly and most probably not the Python way, oh well ... :(
	if len(coders) == 1:
		print("Case #%d: %d %d" % (_c+1, bestC, bestJ))
	elif len(coders) == 2:
		print("Case #%d: %02d %02d" % (_c+1, bestC, bestJ))
	else:
		print("Case #%d: %03d %03d" % (_c+1, bestC, bestJ))