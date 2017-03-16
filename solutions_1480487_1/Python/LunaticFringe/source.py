def solve(x):
	x = x.split('\n')
	tests = int(x[0])
	for i in range(1, tests+1):
		print 'Case #%s:%s' % (i, getAnswer(map(int, x[i].split()[1:])))

def getAnswer(x):
	total = sum(x)
	answer = ''
	for index, num in enumerate(x):
		otherScores = x[:index] + x[index+1:]
		small = 0.0
		big = 100.0
		while big - small > 1e-7:
			mid = (small + big) / 2
			outcome = getOutcome(num + (mid * total / 100), otherScores, total)
			if outcome * 100 + mid < 100:
				small = mid
			else:
				big = mid
		answer += ' %.6f' % mid
	return answer

def getOutcome(scoreToMatch, otherScores, total):
	votes = 0
	for score in otherScores:
		if score >= scoreToMatch: continue
		votes += (scoreToMatch - score) / float(total)
	return votes

# then i run solve() against the input string and paste the output into a new file