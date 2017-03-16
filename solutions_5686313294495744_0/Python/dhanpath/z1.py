import sys
sys.stdin = open( "in1", "r" )
sys.stdout = open( "out1", "w" )

for t in xrange(input()):
	print "Case #"+str(t+1)+":",

	n = input()
	a = [ raw_input().split() for i in range(n) ]

	b1 = {}
	b2 = {}

	for i in range(n):

		if a[i][0] not in b1 :
			b1[ a[i][0] ] = 1
		else :
			b1[ a[i][0] ] += 1
		
		if a[i][1] not in b2 :
			b2[ a[i][1] ] = 1
		else :
			b2[ a[i][1] ] += 1
	
	ans = 0
	for i in range(n):
		if b1[ a[i][0] ] > 1  and  b2[ a[i][1] ] > 1  :
			ans += 1

	print ans