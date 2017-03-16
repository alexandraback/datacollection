import string
import sys

min_difference = sys.maxint
min_c = sys.maxint
min_j = sys.maxint

def slow_solve(scores):
	global min_difference
	global min_c
	global min_j

	if '?' not in scores[0] and '?' not in scores[1]:
		c = int(''.join(scores[0]))
		j = int(''.join(scores[1]))
		difference = abs(c-j)
		if difference < min_difference:
			min_difference = difference
			min_c = c
			min_j = j
		elif difference == min_difference and (c, j) < (min_c, min_j):
			min_c = c
			min_j = j
		return
	for i in range(len(scores[0])):
		if scores[0][i] == '?':
			for j in range(10):
				new_score = scores[0][:]
				new_score[i] = str(j)
				slow_solve([new_score, scores[1]])
			return
		if scores[1][i] == '?':
			for j in range(10):
				new_score = scores[1][:]
				new_score[i] = str(j)
				slow_solve([scores[0], new_score])
			return
	return


def solve(scores):
	global min_difference
	global min_c
	global min_j

	if '?' not in scores[0] and '?' not in scores[1]:
		c = int(''.join(scores[0]))
		j = int(''.join(scores[1]))
		difference = abs(c-j)
		if difference < min_difference:
			min_difference = difference
			min_c = c
			min_j = j
		elif difference == min_difference and (c, j) < (min_c, min_j):
			min_c = c
			min_j = j
		return
	for i in range(len(scores[0])):
		if scores[0][i] == '?' and scores[1][i] == '?':
			combinations = []
			left_scores = [''.join(score[:i]) for score in scores]
			if i == 0:
				combinations = [('0', '0'), ('0', '1'), ('1', '0')]
			elif int(left_scores[0]) < int(left_scores[1]):
				combinations = [('9', '0')]
			elif int(left_scores[0]) > int(left_scores[1]):
				combinations = [('0', '9')]
			else:
				combinations = [('0', '0'), ('0', '1'), ('1', '0')]
			for combo in combinations:
				new_scores = [scores[0][:], scores[1][:]]
				new_scores[0][i] = combo[0]
				new_scores[1][i] = combo[1]
				solve(new_scores)
			return
		if scores[0][i] == '?':
			combinations = []
			left_scores = [''.join(score[:i]) for score in scores]
			key = scores[1][i]
			if i == 0:
				digit = int(key)
				combinations = [str((digit-1)%10), key, str((digit+1)%10)]
			elif int(left_scores[0]) < int(left_scores[1]):
				combinations = ['9']
			elif int(left_scores[0]) > int(left_scores[1]):
				combinations = ['0']
			else:
				digit = int(key)
				combinations = [str((digit-1)%10), key, str((digit+1)%10)]
			for combo in combinations:
				new_score = scores[0][:]
				new_score[i] = combo
				solve([new_score, scores[1]])
			return
		if scores[1][i] == '?':
			combinations = []
			left_scores = [''.join(score[:i]) for score in scores]
			key = scores[0][i]
			if i == 0:
				digit = int(key)
				combinations = [str((digit-1)%10), key, str((digit+1)%10)]
			elif int(left_scores[1]) < int(left_scores[0]):
				combinations = ['9']
			elif int(left_scores[1]) > int(left_scores[0]):
				combinations = ['0']
			else:
				digit = int(key)
				combinations = [str((digit-1) % 10), key, str((digit+1)%10)]
			for combo in combinations:
				new_score = scores[1][:]
				new_score[i] = combo
				solve([scores[0], new_score])
			return
	return

def parse(scores):
	return [list(score) for score in scores.split()]

T = int(raw_input())
for t in range(1, T+1):
	min_difference = sys.maxint
	min_c = sys.maxint
	min_j = sys.maxint
	scores = parse(raw_input())
	length = len(scores[0])
	solve(scores)
	print "Case #%d: %s %s" % (t, str(min_c).zfill(length), str(min_j).zfill(length))
