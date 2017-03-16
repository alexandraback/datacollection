t = {}
def update(a,b):
	for x,y in zip(a,b):
		if x != y:
			assert x not in t or t[x] == y
			t[x] = y
update( 'y qee',
'a zoo')
update('ejp mysljylc kd kxveddknmc re jsicpdrysi',
'our language is impossible to understand')
update('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
'there are twenty six factorial possibilities')
update('de kr kd eoya kw aej tysr re ujdr lkgc jv',
'so it is okay if you want to just give up')

update('z','q')

tn = input()
for loop in xrange(tn):
	print 'Case #%d:'%(loop+1),
	line = raw_input()
	print ''.join(t[x] if x in t else x for x in line)
