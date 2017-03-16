si="""our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""
so="""ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""

m={}
for k in range(len(si)):
	m[so[k]]=si[k]
m['q']='z'
m['z']='q'
#print sorted(m.values())

N=input()
for n in range(N):
	s=raw_input()
	s2=[' ']*len(s)
	for k in range(len(s)):
		s2[k]=m[s[k]]
	print "Case #%d: %s" % (n+1,''.join(s2))

