import sys
import math

def test(i):
	R,T=map(int,raw_input().split(" "))
	N=0
	D=(-(2*R-1)+math.sqrt((2*R-1)*(2*R-1)+2*T))/2
	D=int(D)
	D-=3
	while(1):
		if D>0:
			L=(2*D+2*R-1)*D
			if L>T:
				print("Case #%d: %d"%(i,D-1))
				return
		D+=1
	


N=input()
for i in range(N):
	test(i+1);
