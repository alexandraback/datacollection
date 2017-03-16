#!/usr/bin/python

f = open("C-large-0.in", "r")
f2 = open("C-large-0.out", "w")

def main2():
	R, C, M = map(int, f.readline().split())

	X = R * C - M #number of free cells

	if X < 0:
		# f2.write("\n%d %d %d" % (R, C, X))
		f2.write("\nImpossible")
		return

	if X == 0:
		# f2.write("\n%d %d %d" % (R, C, X))
		f2.write('\n')
		f2.write('\n'.join(['*' * C for i in xrange(R)]))
		return

	if X == 1:
		f2.write('\n')
		table = [['*' for j in xrange(C)] for i in xrange(R)]
		table[0][0] = 'c'
		f2.write('\n'.join([''.join(x) for x in table]))
		return

	if (R == 1) or (C == 1):
		s = ['*' for i in xrange(max(R, C))]
		for i in xrange(X): s[i] = '.'
		s[0] = 'c'
		# f2.write("\n%d %d %d" % (R, C, X))
		f2.write('\n')
		if R == 1:
			f2.write(''.join(s))
		else:
			f2.write('\n'.join(s))
		return

	a, b, r1, r2 = -1, -1, -1, -1
	for i in xrange(2, R + 1):
		for j in xrange(2, C + 1):
			if i * j + i + j < X: continue
			z = j + 1
			if i == R: z = 1

			for k in xrange(z):
				if k != 1:
					k2 = X - i * j - k
					z2 = i
					if j == C: z2 = 0
					if (k2 >= 0) and (k2 != 1) and (k2 <= z2):
						a, b, r1, r2 = i, j, k, k2
						break
			if r2 != -1: break
		if r2 != -1: break

	if r2 == -1:
		# f2.write("\n%d %d %d" % (R, C, X))
		f2.write("\nImpossible")
		return

	table = [['*' for j in xrange(C)] for i in xrange(R)]

	# print a,b,R,C,len(table),len(table[0])
	for i in xrange(a):
		for j in xrange(b):
			table[i][j] = '.'

	# print "case", a, b, r1, r2
	for i in xrange(r1): table[a][i] = '.'
	for i in xrange(r2): table[i][b] = '.'

	# if a < R:
	# 	for i in xrange(r): table[a][i] = '.'
	# elif b < C:
	# 	for i in xrange(r): table[i][b] = '.'
	
	# f2.write("\n%d %d %d" % (R, C, X))
	f2.write('\n')
	table[0][0] = 'c'
	f2.write('\n'.join([''.join(x) for x in table]))

tk = int(f.readline())

for i in xrange(tk):
	f2.write("Case #%d: " % (i + 1))
	main2()
	f2.write('\n')

f.close()
f2.close()

# .....
# .....
# .....
# xxx..
# xxx..