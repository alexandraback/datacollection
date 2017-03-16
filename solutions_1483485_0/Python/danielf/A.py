f = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"
t = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"

A = {}

for i in xrange(len(f)):
	A[f[i]] = t[i]

A['y'] = 'a'
A['e'] = 'o'
A['q'] = 'z'
A['z'] = 'q'


T = int(raw_input())
for i in xrange(T):
	B = ''.join([A[x] for x in raw_input()])
	print "Case #%d: %s" % (i+1, B)
