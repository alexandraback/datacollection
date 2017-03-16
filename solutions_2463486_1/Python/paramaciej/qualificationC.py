#!/usr/bin/env python

T = input()
queries = []
MAX = 1
for i in range(T):
	queries.append([int(b) for b in raw_input().split()])
for q in queries:
	MAX = max(max(q), MAX)

def next(x):
	cyf = [int(c) for c in str(x)]
	cyf[-1] += 1
	ind = len(cyf)-1
	dodac = False
	while cyf[ind] > 2:
		cyf[ind] = 0
		ind -= 1
		if ind < 0:
			dodac = True
			break
		cyf[ind] += 1
	ns = ''
	if dodac:
		ns = '1'
	for i in cyf:
		ns += str(i)
	return int(ns)
	

def ispal(x):
	x = str(x)
	n = len(x)
	for i in range(n/2):
		if x[i] != x[n-i-1]:
			return False
	return True

n = 1
ile = []
quant = 0
while 1:
	if ispal(n):
		pown = n*n
		if ispal(pown):
			if pown > MAX:
				break
			quant += 1
			ile.append(pown)
	if n<3:
		n += 1
	else:
		n = next(n)

T = 1
for q in queries:
	i = 0
	while i < len(ile) and ile[i] < q[0]:
		i += 1
	wynik = 0
	while i < len(ile) and ile[i] <= q[1]:
		wynik += 1
		i += 1
	print "Case #{}: {}".format(T,wynik)
	T += 1
