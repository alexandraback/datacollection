
data = open("B-small.in").readlines()
n = int(data[0])
data = data[1:]
answ = []

for i in xrange(n):
	b, m = map(int, data[i].split(' '))
	aline = []
	if (2 ** (b - 2)) < m:
		aline.append("IMPOSSIBLE\n")
	else:
		aline.append("POSSIBLE\n")
		mat = [[0] * b for j in xrange(b)]
		for x in xrange(b-1):
			for y in xrange(b):
				if x > y:
					mat[y][x] = 1

		for j in xrange(b-2, -1, -1):
			sel = 2**(j-1) if j > 0 else 1
			if sel <= m:
				m -= sel
				mat[j][b-1] = 1
			
		for l in mat:
			aline.append("".join(map(str, l)) + '\n')
	answ.append("".join(aline))

with open("B-small.out", 'w') as f:
	for i, v in enumerate(answ):
		f.write("Case #{}: {}".format(i+1, v))
