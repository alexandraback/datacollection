def lets_try(i, fixed, topics):
	# print(fixed, i, topics)
	if i == len(topics):
		return 0
	if i in fixed:
		return 0
	if(len(topics) == len(fixed)):
		return 0

	l0 = []
	l1 = []
	for j in range(len(topics)):
		if i != j:
			if topics[j][0] == topics[i][0]:
				l0.append(j)
			if topics[j][1] == topics[i][1]:
				l1.append(j)

	maxi = lets_try(i + 1, fixed, topics)
	del topics[i]
	for l in l0:
		for m in l1:
			maxi = max(1 + lets_try(i, fixed | set([l]) | set([m]), topics), maxi)

	return maxi

T = int(raw_input())
for t in range(T):
	N = int(raw_input())
	topics = []
	for n in range(N):
		topics.append(raw_input().split(" "))
	print("Case #"+str(t + 1)+": "+str(lets_try(0, set(), topics)))