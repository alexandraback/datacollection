# coding='utf-8'

import os, sys

sys.stdin = open('B-small-attempt0.in')
sys.stdout = open('B-small-attempt0.out', 'w')


def Work():
	D = int(input())
	P = list(map(int, input().split()))
	ans = max(P)
	for obj in range(1, max(P)):
		steps = [ (x+obj-1)//obj-1 for x in P ]
		ans = min([ans, sum(steps)+obj])
	return ans

if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		print('Case #%d: %d' % (i+1, Work()))
