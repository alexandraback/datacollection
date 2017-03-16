#!/usr/bin/env python3

import sys
def get_ints():
	for line in sys.stdin:
		for word in line.split():
			yield int(word)
	return
ints = get_ints()

def make_key(ls, bot):
	st,tmp,lev = ls
	if st < bot: st = bot
	return (-st, -tmp, -lev)

T = next(ints)
for t in range(T):
	N = next(ints)
	first = []
	second = []
	for i in range(1,N+1):
		a = next(ints)
		b = next(ints)
		first.append((a,-b,i))
		second.append((b,i))
	first.sort()
	first.reverse()
	second.sort()
	second.reverse()
	stars = 0
	used = (N+1)*[False]
	games = 0
	while first or second:
		if second and second[-1][0] <= stars:
			st,lev = second.pop()
			games += 1
			if used[lev]:
				stars += 1
			else:
				stars += 2
			used[lev] = True
			continue
		first.sort(key = lambda x: make_key(x,stars))
		while first and used[first[-1][-1]]:
			first.pop()
		if first and first[-1][0] <= stars:
			st,tmp,lev = first.pop()
			games += 1
			stars += 1
			used[lev] = True
			continue
		else:
			break
	if first or second:
		print("Case #",t+1,": Too Bad",sep='')
	else:
		print("Case #",t+1,": ",games,sep='')
