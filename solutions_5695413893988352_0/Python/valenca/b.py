def sub(l):
	return abs(l[0]-l[1])

for T in range(input()):
	s=list(raw_input())
	c=s[:]
			
	n=s.count('?')
	for i in range(10**n):
		m=1000
		v=str(i).zfill(n)
		k=0
		for j in range(len(s)):
			if s[j]=='?':
				c[j]=v[k]
				k+=1
		dif = sub(map(int,"".join(c).split()))
		if dif < m:
			m = dif
			f = c[:]
		elif dif == m:
			if int("".join(c).split()[0]) < int("".join(f).split()[0]):
				f=c[:]
			elif int("".join(c).split()[0]) == int("".join(f).split()[0]):
				if int("".join(c).split()[1]) < int("".join(f).split()[1]):
					f=c[:]
			
	print "Case #%d: %s" % (T+1,"".join(f))
