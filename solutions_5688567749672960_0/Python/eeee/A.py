def invert(L):
	L = str(L)[::-1]
	ret = int("".join(L))
	return ret

for cases in xrange(input()):
	N = input()
	f = {}
	f[1] = 1
	for k in xrange(1,N):
		if((k+1) in f):
			f[k+1] = min(f[k]+1,f[k+1])
		else:
			f[k+1] = f[k]+1

		ind = invert(k)
		if(ind in f):
			f[ind] = min(f[ind],f[k]+1)
		else:
			f[ind] = f[k]+1
	opt = f[N]
	print "Case #"+str(cases+1)+": "+str(opt)

