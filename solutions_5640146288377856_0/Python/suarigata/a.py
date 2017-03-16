import math

T = int(raw_input())
for t in range(T):
	r,c,w = map(int, raw_input().split())
	soma=r*(c/w)+w
	if c%w==0:
		soma-=1
	
	
	print("Case #" + str(t+1) + ": " + str(int(soma)))
