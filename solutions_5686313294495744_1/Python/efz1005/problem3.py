from copy import deepcopy

def pair_score(pair, firsts, seconds):
	a = firsts.count(pair[0])
	b = seconds.count(pair[1])
	return min(a, b)

T = input()

for qw in xrange(1, T + 1):
	print "Case #%d:" % qw,

	N = input()

	titles = []
	firsts = []
	seconds = []

	for i in xrange(N):
		t = raw_input().split(" ")
		titles.append(t)
		firsts.append(t[0])
		seconds.append(t[1])

	titles_back = deepcopy(titles)
	set_firsts = set(firsts)
	set_seconds = set(seconds)

	if len(set_firsts) == len(firsts) or len(set_seconds) == len(seconds):
		print "0"
		continue

	for word in set_firsts:
		possibles = [pair for pair in titles if pair[0] == word and pair[1] in set_seconds]
		if len(possibles) == 0:
			continue
		m = float("inf")
		for p in possibles:
			score = pair_score(p, firsts, seconds)
			if score == 0:
				titles.remove(p)
			elif score < m:
				m = score
				mP = p
		if mP and mP in titles:
			titles.remove(mP)
		#set_firsts.discard(mP[0])
			set_seconds.discard(mP[1])

	#print titles
	#print set_seconds

	while len(set_seconds) >0:
		for word in set_seconds:
			break
		possibles = [pair for pair in titles if pair[1] == word]
		m = float("inf")
		for p in possibles:
			score = pair_score(p, firsts, seconds)
			if score == 0:
				titles.remove(p)
			elif score < m:
				m = score
				mP = p
		if mP and mP in titles:
			titles.remove(mP)
			set_seconds.discard(mP[1])

	#print titles

	"""set_firsts = set(firsts)
	set_seconds = set(seconds)

	for word in set_seconds:
		possibles = [pair for pair in titles_back if pair[1] == word]
		m = 0
		for p in possibles:
			score = pair_score(p, firsts, seconds)
			if score >= m:
				m = score
				mP = p
		titles_back.remove(mP)
		set_firsts.discard(mP[0])

	for word in set_firsts:
		possibles = [pair for pair in titles_back if pair[0] == word]
		m = 0
		for p in possibles:
			score = pair_score(p, firsts, seconds)
			if score >= m:
				m = score
				mP = p
		titles_back.remove(mP)
"""
	#print #str(max(len(titles), len(titles_back)))
	print str(len(titles))

