#!/usr/bin/python
from sys import stdin
from random import random

T = int(stdin.readline())

def combs(x):
	j, p, s = x
	return [(j, p, None), (j, None, s), (None, p, s)]

def test(J, P, S, K):
	combination = {}
	n = 0
	history = set()
	while True:
		options = {}
		for j in range(1, J+1):
			for p in range(1, P+1):
				for s in range(1, S+1):
					sel = (j, p, s)
					if sel in history: continue
					for c in combs(sel):
						if c not in combination: combination[c] = 0
						if combination[c] == K: break
					else:
						possible = True
						#options[sel] = max(combination[c] for c in combs(sel))
						options[sel] = random()
		if not options: break
		choice = min(options, key=lambda o: options[o])
		history.add(choice)
		n += 1
		for c in combs(choice):
			combination[c] += 1
	return n, history

for i in range(1, T+1):
	J, P, S, K = [int(x) for x in stdin.readline().split()]
	samples = [test(J, P, S, K) for _ in range(20)]
	n, history = max(samples, key=lambda s: s[0])
		
	print('Case #{}: {}'.format(i, n))
	for h in history:
		print(' '.join(str(x) for x in h))
