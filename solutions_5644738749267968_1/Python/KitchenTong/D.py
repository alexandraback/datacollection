def deceivestart(N, Naomi, Ken):
	sNaomi = sorted(Naomi)
	sKen = sorted(Ken)
	score = 0
	while len(sKen):
		if sNaomi[0] > sKen[0]:
			sNaomi = sNaomi[1:]
			sKen = sKen[1:]
			score += 1
		else:
			sNaomi = sNaomi[1:]
			sKen = sKen[:-1]
	return score

def warstart(N, Naomi, Ken):
	sNaomi = sorted(Naomi)
	sKen = sorted(Ken)
	score = 0
	for wood in sNaomi:
		if sKen[0] > wood:
			sKen = sKen[1:]
		else:
			tmp = []
			while len(sKen):
				if sKen[0] < wood:
					tmp.append(sKen[0])
					sKen = sKen[1:]
				else:
					sKen = tmp + sKen[1:]
					tmp = []
					break
			if tmp:
				sKen = tmp[1:]
				score += 1
	return score

if __name__ == "__main__":
	T = int(raw_input())
	for t in xrange(T):
		N = int(raw_input())
		Naomi = map(float, raw_input().split())
		Ken = map(float, raw_input().split())
		print "Case #%d: %d %d" % (t+1, deceivestart(N, Naomi, Ken), warstart(N, Naomi, Ken))