import sys

f = open(sys.argv[1], 'r')
result = open(sys.argv[1]+'.sol','w')
T=eval(f.readline())



print 'T = ', T
for t in range(T):
	print "Case #", t+1
	K,C,S=tuple(map(eval,f.readline().split()))
	print K,C,S
	if C*S<K:
		result.write('Case #'+str(t+1)+': IMPOSSIBLE\n')
	else:
		i = 0
		result.write('Case #'+str(t+1)+':')
		
		while i<K:
			s=0
			for _ in range(C):
				s*=K

				s+=i if i<K else K-1
				print 'i=', i, 's is now ',s
				if i<K:
					i+=1
			print 's=', s
			result.write(' '+str(s+1))
		result.write('\n')

f.close()
result.close()