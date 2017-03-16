# coding='utf-8'

import os, sys

sys.stdin = open('A-large.in')
sys.stdout = open('A-large.out', 'w')

def Work():
	sm, pp = input().strip().split()
	sm = int(sm)
	ret, np = 0, 0
	for i in range(sm+1):
		pi = int(pp[i])
		if np < i: 
			ret += i - np
			np += i - np
		np += pi
	return ret

if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		print('Case #%d: %d' % (i+1, Work()))
