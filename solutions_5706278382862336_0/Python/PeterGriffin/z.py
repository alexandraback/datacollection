import sys
sys.stdin = open('A-small-attempt0.in', 'r')
sys.stdout = open('A.out','w')

for p in range(int(input())):
	P, Q = map(int, input().split('/'))
	import math
	if Q not in [0,1,2,4,8,16,32,64,128,256,512,1024]:
		print("Case #%d: %s" % (p+1, 'impossible'))
	else:
		g = 0
		while P < Q:
			Q //= 2
			g += 1
		print("Case #%d: %d" % (p+1, g))
	

	
