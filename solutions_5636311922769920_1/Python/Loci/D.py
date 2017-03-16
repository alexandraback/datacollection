cases = int(raw_input())


for case in range(cases):
	K,C,S = [int(i) for i in raw_input().split()]

	answer = ' '.join([str(i+1) for i in range(int(K))])

	peopleNeeded = K-(C-1)
	if peopleNeeded <= 0:
		peopleNeeded = 1

	if peopleNeeded > S:
		answer = "IMPOSSIBLE"
	elif S < K:
		answer = []

		totalSize = K**C
		blockSize = K**2
		for person in reversed(range(1,int(peopleNeeded)+1)):

			totalSize = totalSize / 2
			blockSize = blockSize / 2
			answer.append(str(totalSize+blockSize))

		answer = ' '.join(answer)

	print "Case #" + str(case+1) + ": " + answer