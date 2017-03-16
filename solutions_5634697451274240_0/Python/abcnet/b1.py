import sys

f = open(sys.argv[1], 'r')
result = open(sys.argv[1]+'.sol','w')
T=eval(f.readline())
# print 'T = ', T
for t in range(T):
	# print "Case #", t+1
	S=f.readline()
	# print 'S = ', S
	start = S[0]
	# print 'start', start
	prev = S[0]
	kinds = 1
	for curr in S[:-1]:
		# print 'curr', curr
		if curr != prev:
			kinds += 1
			# print 'kinds++'
			prev = curr
	if (start == '+' and kinds%2==1) or (start == '-' and kinds%2==0):
		result.write('Case #'+str(t+1)+': '+str(kinds-1)+'\n')
	else:
		result.write('Case #'+str(t+1)+': '+str(kinds)+'\n')

f.close()
result.close()