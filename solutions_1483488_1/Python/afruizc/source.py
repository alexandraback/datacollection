
def genRecycledPairs(num, A, B):
	st = list(str(num))
	res = []
	for i in range(len(st)-1):
		st.insert(0, st.pop())
		temp = int(''.join(st))
		if A <= num < temp <= B:
			res.append(temp)
	return res

entrada = open('large.in')
salida = open('large.out', 'w')

casos = int(entrada.readline())

for i in range(1, casos+1):
	tot = set()
	A, B = map(int, entrada.readline().split())

	for n in range(A, B):
		rp = genRecycledPairs(n, A, B)
		for m in rp:
			if A <= n < m <= B:
				tot.add((n, m))

	salida.write('Case #%d: %d\n' % (i, len(tot)))

