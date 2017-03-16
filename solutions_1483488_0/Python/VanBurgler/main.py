T = int(input())

for t in range(1, T+1):
	line = input().split()
	A = int(line[0])
	B = int(line[1])
	l = len(list(line[0]))

	options = 0

	for k in range(A, B):
		ks = str(k)
		pairs = set()
		for i in range(1, l):
			new = ks[i:] + ks[:i]
			if k < int(new) and int(new) <= B:
				pairs.add(ks + new)
		options += len(pairs)

	print("Case #{}: {}".format(t, options))