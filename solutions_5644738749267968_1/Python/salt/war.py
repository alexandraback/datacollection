import random


def CheatGame(listKen,listNaomi):
	naomiScore = 0
	while len(listKen) > 0:
		naomiStep = NaomiCheater2(listNaomi,listKen)
		kenStep = Ken(naomiStep,listKen)

		#print "Naomi %f Ken %f" % (naomiStep,kenStep)

		if naomiStep > kenStep:
			naomiScore += 1
	return naomiScore

def StandardGame(listKen,listNaomi):
	naomiScore = 0
	while len(listKen) > 0:
		naomiStep = NaomiLooser(listNaomi)
		kenStep = Ken(naomiStep,listKen)

		#print "Naomi %d Ken %d" % (naomiStep,kenStep)

		if naomiStep > kenStep:
			naomiScore += 1
	return naomiScore

def NaomiCheater(listNaomi,listKen):
	if listNaomi[0] < listKen[len(listKen)-1]:
		listNaomi.pop(0)
		return listKen[len(listKen)-1] - 0.000001
	else:	
		return listNaomi.pop(0)


def NaomiCheater2(listNaomi,listKen):
	bRock = listKen[0]
	index = 0

	while index < len(listNaomi) and listNaomi[index] < bRock:
		index += 1

	if index < len(listNaomi):
		listNaomi.pop(index)
		return listKen[len(listKen)-1] + 0.000001
	else:
		return listNaomi.pop(0)

def NaomiLooser(listNaomi):
	index = random.randint(0,len(listNaomi)-1)
	return listNaomi.pop(index)

def Ken(naomiRock,listKen):
	index = 0
	while index < len(listKen) and listKen[index] < naomiRock:
		index += 1
	if index < len(listKen):
		return listKen.pop(index)
	else:
		return listKen.pop(0)

T = int(raw_input())
for t in range(T):
	size = raw_input()
	naomi = raw_input().split(' ')
	ken = raw_input().split(' ')
	fNaomi = []
	fKen = []
	for k in naomi:
		fNaomi.append(float(k))
	for k in ken:
		fKen.append(float(k))

	fNaomi.sort()
	fKen.sort()
	na = list(fNaomi)
	ke = list(fKen)

	#print na
	#print ke

	print "Case #%d: %d %d" % (t+1,CheatGame(fKen,fNaomi),StandardGame(ke,na))
	