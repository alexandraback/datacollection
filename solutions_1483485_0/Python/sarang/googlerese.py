A = 'ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvzq'
B = 'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upqz'

t = int(raw_input())
for c in range(1,t+1):
	l = raw_input()
	op = ""
	for i in xrange(len(l)):
		if(l[i] != ' '): op += B[A.find(l[i])];
		else: op+=' '
	print "Case #%d: %s"%(c,op)
