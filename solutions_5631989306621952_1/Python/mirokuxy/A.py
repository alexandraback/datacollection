import sys


T = 0
S = ""

lineCount = 0

def process(S):
	res = []

	for c in S:
		if len(res) == 0:
			res.append(c)
		else:
			if(res[0] > c):
				res.append(c)
			else:
				res.insert(0, c)

	return res


for line in sys.stdin:
	line = line.strip()
	if not line:
		break

	if lineCount == 0:
		T = int(line)
	else:
		S = line
		res = process(S)
		res = ''.join(res)
		print "Case #%d: %s" % (lineCount, res)

	lineCount += 1

