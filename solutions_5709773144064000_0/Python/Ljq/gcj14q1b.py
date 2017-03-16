
import sys
sys.stdin = open('B-small-attempt0.in')
sys.stdout = open('B-small-attempt0.out', 'w')

import matplotlib.pyplot as plt

def CalcTime(tms):
	ret, ff = 0, 2
	for i in range(tms):
		ret += c / ff
		ff += f
	ret += obj / ff
	return ret

def Work():
	global c, f, obj
	c, f, obj = map(float, input().split())

	ll, rr = 0, 100000
	while ll + 5 < rr:
		mid1, mid2 = ll+(rr-ll)//3, rr-(rr-ll)//3
		t1, t2 = CalcTime(mid1), CalcTime(mid2)
		if t1 < t2: rr = mid2
		else: ll = mid1
	xlst = [CalcTime(x) for x in range(ll, rr)]
	return min(xlst)

if __name__ == '__main__':
	T = int(input())
	for t in range(1, T+1):
		print('Case #%d: %.10f' % (t, Work()))
