from fractions import gcd

f = open('A-large.in')
fw = open('A-large-output.txt', 'w')

cases = int(f.readline())
for case in range(cases):
	P, Q = map(int, f.readline().split('/'))
	div = gcd(P, Q)
	P = P / div
	Q = Q / div

	gen = 1
	while Q % 2 == 0 and P < Q / 2:
		Q = Q / 2
		gen += 1

	ans = 'impossible'
	if Q % 2 == 0:
		while Q > 2:
			if Q % 2 == 0:
				Q = Q / 2
			else:
				break
		if Q == 2:
			ans = gen
			if gen > 40:
				print 'error: gen > 40'

	print str(case + 1) + ': ' + str(ans)
	fw.write('Case #' + str(case + 1) + ': ' + str(ans) + '\n')

fw.close()
f.close()
