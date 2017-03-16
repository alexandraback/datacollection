# 

import math
import Queue
import copy

nglobal = 0

def altura(mapa, x):
	return mapa[x + 200]

def setaltura(mapa, x, h):
	mapa[x + 200] = h

def solve(mapa, p, n, px, py):
	if n == 0:
		# print nglobal-n, 'retorna1', 0
		return 0

	h = altura(mapa, 0)
	x = 0

	# print nglobal-n, 'encontrou obstaculo', h

	mapac = mapa[:]
	if h == -1:
		setaltura(mapac, x, 0)

		if (x,altura(mapac, x)) == (px,py):
			return p

		sp = solve(mapac[:], p, n-1, px, py)

		# print nglobal-n, 'retorna', p*sp
		# print nglobal-n, 'retorna2', p*sp
		return p*sp

	if altura(mapa, x-1) == altura(mapa, x) + 1:
		# print 'porra'
		sp1 = None
	else:
		xc = x
		mapac = mapa[:]
		while True:
			if altura(mapac, xc-2) == -1:
				setaltura(mapac, xc-2, 0)
				xc = xc-2
				break

			if altura(mapac, xc-2) == altura(mapac, xc):
				setaltura(mapac, xc-1, altura(mapac, xc) + 1)
				xc = xc-1
				break

			xc -= 2

		# print nglobal-n, 'left parou de cair na pos', (xc, altura(mapac, xc))

		if (xc, altura(mapac, xc)) == (px, py):
			sp1 = p
		else:
			sp1 = solve(mapac, p, n-1, px, py)

	sp2 = 0
	if altura(mapa, x+1) == altura(mapa, x) + 1:
		sp2 = None
	else:
		xc = x
		mapac = mapa[:]
		while True:
			if altura(mapac, xc+2) == -1:
				setaltura(mapac, xc+2, 0)
				xc = xc+2
				break

			if altura(mapac, xc+2) == altura(mapac, xc):
				setaltura(mapac, xc+1, altura(mapac, xc) + 1)
				xc = xc+1
				break

			xc += 2

		# print nglobal-n, 'right parou de cair na pos', (xc, altura(mapac, xc)), mapac[198:203]

		if (xc, altura(mapac, xc)) == (px, py):
			sp2 = p
		else:
			sp2 = solve(mapac, p, n-1, px, py)

	if sp1 is None and sp2 is None:
		# print 'here1'
		return p
	if sp1 is None:
		# print 'here2'
		# print nglobal-n, 'retorna3', p*sp2
		return p*sp2
	if sp2 is None:
		# print 'here3'
		return p*sp1

	# print nglobal-n, 'retorna4', p*(sp1/2 + sp2/2)

	return p*(sp1/2 + sp2/2)

def main():
	global nglobal

	# fp = open('b.in')
	fp = open('B-small-attempt1.in')
	# fp = open('B-large.in')

	for case in xrange(int(fp.readline())):
		n,x,y = map(int, fp.readline().split())

		nglobal = n

		mapa = [-1] * 600

		result = solve(mapa, 1.0, n, x, y)

		print 'Case #{0}: {1}'.format(case+1, result)

if __name__ == "__main__":
	main()
