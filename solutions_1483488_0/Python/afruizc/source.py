
def genRecycledPairs(num):
	st = list(str(num))
	res = []
	for i in range(len(st)-1):
		st.insert(0, st.pop())
		res.append(int(''.join(st)))

	return res

entrada = open('small.in')
salida = open('small.out', 'w')

casos = int(entrada.readline())

for i in range(1, casos+1):
	tot = set()
	A, B = map(int, entrada.readline().split())

	for n in range(A, B+1):
		rp = genRecycledPairs(n)
		for m in rp:
			if A <= n < m <= B:
				tot.add((n, m))

	salida.write('Case #%d: %d\n' % (i, len(tot)))

