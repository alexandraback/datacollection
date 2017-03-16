def function():
	r,c,w = raw_input("").split(" ")
	r,c,w = int(r), int(c), int(w)
	score = 0
	for i in range(r):
		cur_score = c/w
		if w != 1:
			if c%w == 0:
				cur_score -= 1
			cur_score += w
		score += cur_score
	return score

t = int(raw_input(""))
for i in range(1, t + 1):
	print "Case #%s: %s" % (i, function())
    