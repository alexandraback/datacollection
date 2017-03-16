#!/usr/bin/env python
import sys
import math

t_n = int(sys.stdin.readline())

def isqrt(x):
	n = int(x)
	if n == 0:
		return 0;
	a, b = divmod(n.bit_length(),2)
	x = 2**(a+b)
	while True:
		y = (x+n//x)//2
		if y >= x:
			return x
		x = y
		
for t_t in range(1, t_n+1):
	m = []
	[a, b] = map(int, sys.stdin.readline().split())
	low = int(isqrt(a))
	if low*low < a:
		low += 1
	high = int(isqrt(b))
	ans = 0
	for i in range(low,high+1):
		s = str(i)
		rs = s[::-1]
		if s == rs:
			l = str(i*i)
			if l == l[::-1]:
				ans += 1
	print("Case #%d: %d" % (t_t, ans))
