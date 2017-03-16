for T in range(1, int(input())+1):
	C, J = input().split()

	equals = True
	Cscore = 0
	Jscore = 0

	for i in range(len(C)):
		Cscore *= 10
		Jscore *= 10
		if C[i] == '?' and J[i] == '?':
			if Cscore == Jscore:
				Cscore += 0
				Jscore += 0
			elif Cscore < Jscore:
				Cscore += 9
				Jscore += 0
			elif Cscore > Jscore:
				Jscore += 9
				Cscore += 0

		elif C[i] == '?' and J[i] != '?':
			if Cscore == Jscore:
				Cscore += int(J[i])
				Jscore += int(J[i])
			elif Cscore < Jscore:
				Cscore += 9
				Jscore += int(J[i])
			elif Cscore > Jscore:
				Cscore += 0
				Jscore += int(J[i])

		elif C[i] != '?' and J[i] == '?':
			if Cscore == Jscore:
				Cscore += int(C[i])
				Jscore += int(C[i])
			elif Cscore < Jscore:
				Cscore += int(C[i])
				Jscore += 0
			elif Cscore > Jscore:
				Cscore += int(C[i])
				Jscore += 9

		elif C[i] != '?' and J[i] != '?':
			Cscore += int(C[i])
			Jscore += int(J[i])

	a = str(Cscore)
	b = str(Jscore)

	print('Case #{}: {} {}'.format(T, a.rjust(len(C), '0'), b.rjust(len(C), '0')))