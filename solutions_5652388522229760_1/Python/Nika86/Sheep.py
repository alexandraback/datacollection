#! /usr/bin/python

def getLastMultiplier(N):
	digitCount = 0
	digitEncountered = [False for _ in range(10)]

	multiplier = 0
	while True:
		multiplier += 1
		multiple = N * multiplier

		while multiple > 0:
			digit = multiple % 10
			multiple /= 10

			if not digitEncountered[digit]:
				digitEncountered[digit] = True
				digitCount += 1

		if 10 == digitCount:
			return multiplier


T = int(raw_input())

for t in range(1, T+1):

	N = int(raw_input())
	if 0 == N:
		print 'Case #' + str(t) + ': ' + 'INSOMNIA'
	else:
		print 'Case #' + str(t) + ': ' + str(N * getLastMultiplier(N))