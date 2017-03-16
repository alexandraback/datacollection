def rec(energy, gain, cnt):
	#print energy,gain,cnt
	energy = energy+R
	if energy>E:
		energy=E
	if cnt>N-1:
		return gain
	for j in range(R,energy+1):
		res.append(rec(energy-j, gain+(v[cnt]*j), cnt+1))
		#print res

fi = open('input.txt','r')
t = int(fi.readline())
for i in range(0,t):
	#print i
	E,R,N = map(int,fi.readline().split())
	v = map(int,fi.readline().split())
	
	if(E<=R):
		s = 0
		for k in v:
			s = s+k
		print "Case #{0}: {1}".format(i+1,s*E)
		continue

	res = []
	v.sort()

	rec(E,0,0)

	#print res
	print "Case #{0}: {1}".format(i+1,max(res))
fi.close