def all_consonants(s):
	for c in s:
		if c in 'aeiou':
			return False
	return True

def n_score(n, name):
	l = len(name)
	offsets = []
	score = 0
	for i in range(l - n + 1):
		if all_consonants(name[i:i+n]):
			offsets.append(i)
	for i in range(l):
		if len(offsets) == 0:
			break
		score += l - (offsets[0] + n) + 1
		if offsets[0] == i:
			offsets = offsets[1:]
	return score

cases = int(raw_input())
for case in range(cases):
	name, n = raw_input().split(' ')
	score = n_score(int(n), name)
	print 'Case #%d: %d' % (case + 1, score)