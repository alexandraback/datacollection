#Grzegorz Prusak
from sys import stdin

M = {'a':'y', 'o':'e', 'q':'z', 'z':'q'}

with open('sample.in','r') as i:
	with open('sample.out','r') as o:
		n = int(i.readline())
		for id,il,ol in zip(range(0,n),i,o):
			ol = ol.split(': ')[1]
			for ci,co in zip(il,ol): M[ci] = co

n = int(stdin.readline())
for i in range(0,n):
	print 'Case #%d:'%(i+1), ''.join(map(lambda c: M[c],stdin.readline())),
