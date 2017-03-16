T = int(raw_input())
for t in range(1, T+1):
	raw_input()
	naomi = sorted([float(i) for i in raw_input().split()])
	ken = sorted([float(i) for i in raw_input().split()])
	naomi1 = naomi[:]
	ken1 = ken[:]
	war_score = len(naomi1)
	for naomi_rock in naomi1:
		for i in range(len(ken1)):
			if ken1[i] > naomi_rock:
				war_score-=1
				break
		ken1 = ken1[i+1:]
	dwar_score = 0
	for ken_rock in ken:
		for i in range(len(naomi)):
			if naomi[i] > ken_rock:
				dwar_score+=1
				break
		naomi = naomi[i+1:]
	print "Case #%d: %d %d" % (t, dwar_score, war_score)

