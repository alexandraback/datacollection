fi = open("B-large.in")
fo = open("B-large.out", "w")

line = next(fi)
T = int(line)
for t in range(T):
	line = next(fi)
	[B, M] = [int(x) for x in line.rstrip().split(' ')]
	w = 'IMPOSSIBLE\n'
	m = 2 ** (B-2)
	if M <= m:
		w = 'POSSIBLE\n'
		w += '0'
		while m > 0:
			m //= 2
			if m > 0:
				if M >= m:
					w += '1'
					M -= m
				else:
					w += '0'
		w += '1\n' if M > 0 else '0\n'

		for i in range(B-1):
			for j in range(B):
				w += '1' if j > i + 1 else '0'
			w += '\n'

	fo.write("Case #" + str(t+1) + ": " + str(w))

fi.close()
fo.close()
