def solve2(ar0, ar1, ar2, indQ, indK):
	h0 = ar0[indK]
	h1 = ar1[indK]

	if h0 == h1:
		return h0

	return list(set([h0, h1]) - set([ar2[indQ]]))[0]


def solve(N, ars):
	grouped_ars = []
	lost_index = -1;
	for i in range(N):
		key = lambda x: x[i]
		ars.sort(key = key)
		if (len(ars) > 1) and (key(ars[0]) == key(ars[1])):
			count = 2
		else:
			count = 1
			lost_index = i

		grouped_ars.append(ars[:count])
		ars = ars[count:]

	lost = []
	for i in range(N):
		if i == lost_index:
			lost.append(grouped_ars[lost_index][0][i])
		else:
			ar0 = grouped_ars[i][0]
			ar1 = grouped_ars[i][1]
			ar2 = grouped_ars[lost_index][0]
			lost.append(solve2(ar0, ar1, ar2, i, lost_index))

	return " ".join(map(str, lost))


n = int(input())

for i in range(n):
	N = int(input())
	ars = []
	for j in range(2*N - 1):
		ars.append(list(map(int, input().split())))

	print(("Case #%d: " % (i+1)) + str(solve(N, ars))) #i