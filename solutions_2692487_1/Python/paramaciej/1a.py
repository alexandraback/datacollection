#!/usr/bin/env python3

t = int(input())
for case in range(1,t+1):
	A, N = [int(x) for x in input().split()]
	tab = sorted([int(x) for x in input().split()])

	rozmiar = A
	ruchy = 0
	minr = 10**60

	i = 0
	while i < len(tab):
		if ruchy >= minr:
			break

		zostalo = len(tab)-i
		x = tab[i]

		if x < rozmiar:
			rozmiar += x
			i += 1
			if i == len(tab):
				minr = min(minr, ruchy)
		else:
			if rozmiar < 2:
				ruchy += zostalo
				minr = min(minr, ruchy)
				break
			else:
				minr = min(minr,ruchy+zostalo)
				rozmiar += (rozmiar-1)
				ruchy += 1

	print('Case #{}: {}'.format(case, minr))
