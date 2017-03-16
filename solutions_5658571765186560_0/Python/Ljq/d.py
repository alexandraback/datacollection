# coding='utf-8'

import os, sys

sys.stdin = open('D-small-attempt2.in')
sys.stdout = open('D-small-attempt2.out', 'w')

def Work():
	X, R, C = map(int, input().split())
	if R < C: R, C = C, R
	# R >= C
	if X == 1: return True
	if X >= 7: return False
	if R * C % X > 0: return False
	if X > R: return False
	if X - 2 >= C: return False
	return True

if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		ans = 'GABRIEL' if Work() else 'RICHARD'
		print('Case #%d: %s' % (i+1, ans))
