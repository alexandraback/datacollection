#! /usr/bin/env python
from itertools import count
from math import sqrt
from collections import deque
from copy import copy

fname = 'D-small-attempt0'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')

def war(naomi, ken):
	i = 0
	for n in naomi:
		for pos, k in enumerate(ken):
			if k > n and k != -1:
				ken[pos] = -1
				break
		else:
			i += 1
			ken.popleft()
	return i
	
def deceitful_war(naomi, ken):
	win = 0
	for i in xrange(len(naomi)):
		if naomi[0] < ken[0]:
			# naomi blufs that she has a little less than ken's highest
			ken.pop()
			naomi.popleft()
		else:
			# naomi can win by playing her lowest and saying she'll win high
			ken.popleft()
			naomi.popleft()
			win += 1
	return win

def solve(fin):
	N = int(fin.readline().split()[0])
	naomi = map(float, fin.readline().split())
	ken = map(float, fin.readline().split())
	ns = deque(sorted(naomi))
	ks = deque(sorted(ken))
	return str(deceitful_war(ns, copy(ks)))+" "+str(war(naomi, ks))
	
T = int(fin.readline())

for i in xrange(1,T+1):
	fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
