#!/usr/bin/env python

T = input()
for case in range(1,T+1):
	n,m = raw_input().split()
	n = int(n)
	m = int(m)
	tab = []
	for i in range(n):
		tab.append([int(x) for x in raw_input().split()])
	end = [[100 for j in range(m)] for i in range(n)]

	for i in range(n):
		bmax = max(tab[i])
		end[i] = [bmax for j in range(m)]

	for j in range(m):
		bmax = max([tab[i][j] for i in range(n)])
		for i in range(n):
			end[i][j] = min(bmax, end[i][j]);

	if end == tab:
		print "Case #{}: YES".format(case)
	else:
		print "Case #{}: NO".format(case)
