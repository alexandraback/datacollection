from itertools import *

def canpay(denoms, i):
	if (i == 0):
		return True
	if (i < 0):
		return False
	sorteddenoms = list(denoms)
	sorteddenoms.sort()
	for d in sorteddenoms:
		if (d > i):
			continue
		newdenoms = denoms - set([d])
		if canpay(newdenoms, i-d):
			return True
	return False

def solve(c, denoms, v):
	possibles = set(range(1,v+1))-denoms
	for n in range(len(possibles)+1):
		for newcoins in combinations(possibles, n):
			newdenoms = denoms|set(newcoins)
			works = True
			for i in range(1, v+1):
				if not canpay(newdenoms, i):
					works = False
					break
			if works:
				return n
	

numcases = int(input())
for i in range(numcases):
	c, d, v = [int(i) for i in input().split(" ")]
	denoms = [int(i) for i in input().split(" ")]
	print("Case #" + str(i+1) + ":", solve(c, set(denoms), v));