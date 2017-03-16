

cases = int(raw_input())


for case in range(cases):
	N = int(raw_input())
	answer = 0
	done = {'1','2','3','4','5','6','7','8','9','0'}

	if N == 0:
		answer = "INSOMNIA"
	else:
		val = N
		multiplier = 1

		while 1:
			for c in str(val*multiplier):
				if c in done:
					done.remove(c)

			answer = val*multiplier
			multiplier += 1


			if len(done) == 0:
				break

	answer = str(answer)

	print "Case #" + str(case+1) + ": " + answer








