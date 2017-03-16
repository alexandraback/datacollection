def fonction(N, s):
	S = sum(s)
	solutions = []
	for k in range(N):
		barre = s[k]
		ss = sorted(s)
		j = ss.index(barre)
		candidats = ss[:j + 1]
		while len(candidats) * barre - sum(candidats) <= S and j + 1 < N:
			j += 1
			barre = ss[j]
			candidats.append(ss[j])
		# print(candidats)
		# print([t - s[k] for k in range(j + 1)])
		# print("Du coup on en arrive à", j, sum([t - s[k] for k in range(j + 1)]))
		if len(candidats) * barre - sum(candidats) > S:
			candidats = candidats[:-1]
			barre = candidats[-1]
		# print("Après réajustement", candidats, barre, "barre - s[0]", barre - s[0], (barre - s[k] + (S - len(candidats) * barre + sum(candidats)) / len(candidats)) / S)
		# print("Il reste", reste)
		# return reste * 100 / S
		if round(100 * (barre - s[k] + (S - len(candidats) * barre + sum(candidats)) / len(candidats)) / S, 6) < 0:
			solutions.append("0")
		else:
			solutions.append(str(round(100 * (barre - s[k] + (S - len(candidats) * barre + sum(candidats)) / len(candidats)) / S, 6)))
	return solutions

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		args = [int(_) for _ in input().split()]
		N = args[0]
		s = args[1:]
		print("Case #{}: {}".format(t + 1, " ".join(fonction(N, s))))
