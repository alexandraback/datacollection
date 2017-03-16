import fileinput

lines = fileinput.input()
lines.next()
for i,line in enumerate(lines):
	fields = map(int, line.split())
	S = fields[1]
	p = fields[2]
	scores = fields[3:]
	n = 0
	if p == 0:
		n = len(scores)
	else:
		for score in scores:
			if score == 0:
				continue
			elif score > 3 * (p - 1):
				n += 1
			elif score >= 3 * (p - 1) - 1:
				if S > 0:
					S -= 1
					n += 1
	print "Case #%d:" % (i+1), n

