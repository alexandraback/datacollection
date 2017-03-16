from string import maketrans

table=maketrans("ynficwlbkuomxsevzpdrjgathaq","abcdefghijklmnopqrstuvywxyz")
T=int(raw_input())
for repeat in xrange(T):
	go=raw_input()
	en=go.translate(table)
	print "Case #%d:"%(repeat+1),
	print en
