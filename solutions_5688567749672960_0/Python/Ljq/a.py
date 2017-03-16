# coding='utf-8'

import os, sys, time
time.clock()

sys.stdin = open('A-small-attempt0.in')
sys.stdout = open('A-small-attempt0.out', 'w')

def flip(x):
	return int(str(x)[::-1].lstrip('0'))

def Preprocess():
	global f
	n = 1000002
	f = [n] * n
	f[1] = 1
	for i in range(1, n-1):
		f[i+1] = min(f[i+1], f[i] + 1)
		if flip(i) < n:
			f[flip(i)] = min(f[flip(i)], f[i]+1)

def Work():
	n = int(input().strip())
	return f[n]

if __name__ == '__main__':
	Preprocess()
	T = int(input())
	for i in range(T): 
		print('Case #%d: %d' % (i+1, Work()))
	sys.stderr.write('completed %.3f\n' % time.clock())
