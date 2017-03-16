import sys
sys.stdin = open( "in", "r" )
sys.stdout = open( "out", "w" )

for t in range(input()):
	k,c,s = map(int,raw_input().split())
	print "Case #"+str(t+1)+": ",
	for i in range(k):
		print i+1,
	print ''