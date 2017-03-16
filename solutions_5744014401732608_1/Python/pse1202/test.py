filename = 'B-large.in'
f = open(filename,'r')
T = int(f.readline())
for i in range(1,T+1):
	print "Case #%d:" % i,
	B,M = map(int,f.readline().rstrip().split())

	if M > 2**(B-2):
		print "IMPOSSIBLE"
	else:
		print "POSSIBLE"
		x = '1' + bin(M-1)[2:][::-1] + '0'*(B-2 -len(bin(M-1)[2:])) + '0'
		for i in range(B):
			print '0'*min(B-1,i+1) + '1'*max(0,B-i-2) + x[i]