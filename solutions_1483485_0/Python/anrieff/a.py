#!/usr/bin/python

crypted = ["ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv", "y qee", "z"]
decrypted=["our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up", "a zoo", "q"]

D = {}
DC = {}

for i in xrange(len(crypted)):
	for j in xrange(len(crypted[i])):
		c = crypted[i][j]
		if c == ' ': continue
		d = decrypted[i][j]
		DC[d] = 1
		if c in D:
			assert D[c] == d, "mismatch"
		else:
			D[c] = d

#for key in sorted(D.keys()):
	#print "%s -> %s" % (key, D[key])

#print sorted(DC.keys())

assert len(D) == 26, "Dictionary incomplete"
D[' '] = ' '

T = int(raw_input().strip())

for i in xrange(1, T + 1):
	s = raw_input().strip()
	print "Case #%d: %s" % (i, "".join(map(lambda c: D[c], list(s))))
