#Author Zhuojie
before=['ejp mysljylc kd kxveddknmc re jsicpdrysi',
'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
'de kr kd eoya kw aej tysr re ujdr lkgc jv','y qee','z']
after=['our language is impossible to understand',
'there are twenty six factorial possibilities',
'so it is okay if you want to just give up','a zoo','q']

c = zip("".join(before),"".join(after))
d=dict(c)

n=input()
for i in range(n):
	s=raw_input()
	print "Case #%d: %s" % (i+1,"".join(map(lambda x: d[x],s)))
