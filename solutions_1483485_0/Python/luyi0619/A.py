a = [] 
b = []

a.append('ejp mysljylc kd kxveddknmc re jsicpdrysi')
a.append('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd')
a.append('de kr kd eoya kw aej tysr re ujdr lkgc jv')

b.append('our language is impossible to understand')
b.append('there are twenty six factorial possibilities')
b.append('so it is okay if you want to just give up')

memo = {}

for i in xrange(len(a)):
	for j in xrange(len(a[i])):
		memo[ a[i][j]  ]  = b[i][j]

memo['z'] = 'q'
memo['q'] = 'z'

t = map(int,raw_input().split())[0]

cas = 1

while t > 0:
	t-=1
	s = ""
	val = raw_input()
	for i in xrange( len(val) ):
		s += memo[ val[i] ];
	print "Case #%d: %s" % (cas,s)
	cas += 1  