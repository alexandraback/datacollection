from sys import stdin
english    = "zq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"
googlerese = "qz ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
mapping = dict(zip(googlerese, english))
lines = map(lambda x: x.strip(), stdin.readlines())
for i in range(1, len(lines)):
	print "Case #%s: %s" % (i, "".join([mapping[char] for char in lines[i]]))

