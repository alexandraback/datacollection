def close_match(i, C, J):
	if(i == len(C)):
		Jn = int(''.join(J))
		Cn = int(''.join(C))
		return (abs(Jn- Cn), ''.join(C), ''.join(J))
	poss = []
	Ccopy = [C[:] for k in range(10)]
	if(C[i] == '?'):
		for k in range(10):
			Ccopy[k][i] = str(k)
	Jcopy = [J[:] for k in range(10)]
	if(J[i] == '?'):
		for k in range(10):
			Jcopy[k][i] = str(k)
	if C[i] == '?' and J[i] == '?':
		for l in range(10):
			for m in range(10):
				poss.append(close_match(i + 1, Ccopy[l], Jcopy[m]))

	elif C[i] == '?':
		for l in range(10):
			poss.append(close_match(i + 1, Ccopy[l], J))

	elif J[i] == '?':
		for l in range(10):
			poss.append(close_match(i + 1, C, Jcopy[l]))		

	else:
		poss.append(close_match(i + 1, C, J))	
	# print(poss)
	mini = poss[0][0]
	mini_C = poss[0][1]
	mini_J = poss[0][2]
	for opt in poss:
		Jn = int(opt[2])
		Cn = int(opt[1])
		if mini > opt[0]:
			mini = opt[0]
			mini_C = opt[1]
			mini_J = opt[2]	
		elif mini == opt[0]:
			if mini_C == opt[1]:
				if int(mini_J) > Jn:
					mini_J = opt[2]
			else:
				if  int(mini_C) > Cn:
					mini_C =opt[1]

	return [mini, mini_C, mini_J]




T = int(raw_input())
for t in range(T):
	l = raw_input().split(" ")
	C = l[0]
	J = l[1]
	# print(C, J)
	sol = close_match(0, list(C), list(J))
	print("Case #"+str(t + 1)+": "+sol[1]+" "+sol[2])