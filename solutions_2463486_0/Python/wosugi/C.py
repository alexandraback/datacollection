# -*- coding: utf-8 -*-
import sys
import bisect

D = int(100/2)
fsnums = []

def search_fixed_digits(d,k=0,cap=9,num=0):
	if cap<0: return
	if d<=2*k:
		fsnums.append(num*num)
		return
#	for n in range(1 if k==0 else 0,10):
	for n in range(1 if k==0 else 0,3): #only 0,1,2 can satisfy the condition
		num2,cap2 = num,cap
		if 2*k==d-1: #d-th digit locates the exact center
			num2 += (10**k)*n
			cap2 -= n*n
		else:
			num2 += (10**k+10**(d-1-k))*n
			cap2 -= n*n*2
		search_fixed_digits(d,k+1,cap2,num2)
	return

def find_fair_square_numbers():
	#store the answers of numbers with 1-digit in advance
	fsnums.append(1*1)
	fsnums.append(2*2)
	fsnums.append(3*3)
	#search numbers with d-digits
	for d in range(2,D+1):
		#print('# of digits: {}'.format(d),file=sys.stderr)
		search_fixed_digits(d)
	return

if __name__ == '__main__':
	find_fair_square_numbers()
#	print('Length={}'.format(len(fsnums)),file=sys.stderr)
#	print(fsnums,file=sys.stderr)
	T = int(input())
	for t in range(T):
		a,b = [int(i) for i in sys.stdin.readline().split()]
		ans = bisect.bisect_right(fsnums,b)-bisect.bisect_left(fsnums,a)
		print('t={} a={} b={} ANS={}'.format(t+1,a,b,ans),file=sys.stderr)
		print('Case #{}: {}'.format(t+1,ans))
