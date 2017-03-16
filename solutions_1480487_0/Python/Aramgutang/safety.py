# Usage: python safety.py input.txt > output.txt
from decimal import Decimal
from operator import add
import sys

def floatrange(start, stop, step):
	yield start
	extra = 0.0
	while start <= stop:
		start += step + extra
		extra = (yield start)
		if extra is None:
			extra = 0.0

with open(sys.argv[1]) as input:
	input.next()
	for case, line in enumerate(input, 1):
		judge_scores = map(int, line.strip().split(' ')[1:])
		contestants = len(judge_scores)
		sum = reduce(add, judge_scores)
		audience_scores = []
		for index, score in enumerate(judge_scores):
			others = judge_scores[:index] + judge_scores[index+1:]
			others.sort()
			increments = floatrange(0.0, 1.0, 0.000000001)
			for audience_score in increments:
				total = audience_score * sum + score
				left_over = 1.0 - audience_score
				for other in others:
					if other < total:
						left_over -= (total - other) / float(sum)
					else:
						break
				if left_over <= 0:
					break
				elif left_over > 0.01:
					increments.send(0.00001)
				else:
					increments.send(0.0)
			audience_scores.append(audience_score*100.0)
		print 'Case #%s: %s' % (
			case,
			' '.join(map(lambda x: '%6f' % Decimal(str(x)), audience_scores))
		)