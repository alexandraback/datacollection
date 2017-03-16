import sys
sys.stdin = open( "in", "r" )
sys.stdout = open( "out", "w" )

for t in range(input()):
	print "Case #"+str(t+1)+":",
	n = input()
	a = [0]*2555
	for i in range(2*n-1):
		for x in map(int,raw_input().split()) :
			a[x] += 1
	for i in range(2555):
		if a[i] % 2 :
			print i,
	print ''