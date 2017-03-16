import sys

for T in range(1, int(input())+1):
	N = int(input())

	subj1, subj2 = {}, {}
	subjects = []
	for i in range(N):
		w1, w2 = tuple(input().split())
		subjects.append((w1, w2))
		subj1[w1] = subj1.get(w1, []) + [w2]
		subj2[w2] = subj2.get(w2, []) + [w1]

	def val(s):
		return min(len(subj1[s[0]]), len(subj2[s[1]]))

	res = 0

	while len(subjects) > 0:
		subjects.sort(key=val)
		w1, w2 = subjects.pop(0)
		subj1[w1].remove(w2)
		subj2[w2].remove(w1)
		res += 1
		newsubj1w1 = subj1[w1][:]
		for ww2 in subj1[w1]:
			if len(subj2[ww2]) > 1:
				subjects.remove((w1, ww2))
				subj2[ww2].remove(w1)
				newsubj1w1.remove(ww2)
		subj1[w1] = newsubj1w1

		newsubj2w2 = subj2[w2][:]
		for ww1 in subj2[w2]:
			if len(subj1[ww1]) > 1:
				subjects.remove((ww1, w2))
				subj1[ww1].remove(w2)
				newsubj2w2.remove(ww1)
		subj2[w2] = newsubj2w2

	print('Case #{}: {}'.format(T, N - res))
