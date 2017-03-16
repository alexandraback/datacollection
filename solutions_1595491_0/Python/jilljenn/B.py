def fonction(N, S, p, points):
	nbSurprises = S
	nbChampions = 0
	for n in points:
		if n // 3 >= p or (n // 3 == p - 1 and n % 3 > 0):
			nbChampions += 1
		elif nbSurprises > 0 and ((n // 3 == p - 1 and n > 0 and n % 3 == 0) or (n // 3 == p - 2 and n % 3 == 2)):
			nbChampions += 1
			nbSurprises -= 1
	return nbChampions

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		args = [int(_) for _ in input().split()]
		N, S, p = args[:3]
		points = args[3:]
		print("Case #{}: {}".format(t + 1, fonction(N, S, p, points)))
