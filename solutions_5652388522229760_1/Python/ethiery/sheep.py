T = int(input())

for i in range(T):
	N = int(input())
	currentNb = N
	seen = [False] * 10
	seenNb = 0
	for j in range(1000000):
		s = str(currentNb)
		for c in s:
			digit = ord(c) - 48
			if seen[digit] == False:
				seen[digit] = True
				seenNb += 1
		if seenNb == 10:
			print("Case #{}: {}".format(i+1, currentNb))
			break
		currentNb += N
	if seenNb != 10:
		print("Case #{}: {}".format(i+1, 'INSOMNIA'))
