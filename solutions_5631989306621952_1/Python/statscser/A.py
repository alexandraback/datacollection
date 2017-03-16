out = open('outputA_l.txt', 'w')
with open('A-large.in', 'r') as f:
	T = int(f.readline())
	for i in range(1, T+1):
		out.write('Case #%s: ' % i)
		S = f.readline().strip()
		res = S[0]
		for i in range(1, len(S)):
			if S[i] >= res[0]:
				res = S[i] + res
			else:
				res = res + S[i]
		out.write('%s\n' % res)

out.close()

