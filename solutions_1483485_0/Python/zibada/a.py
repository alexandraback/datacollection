from string import maketrans
n = input()
a = "abcdefghijklmnopqrstuvwxyz"
b = "yhesocvxduiglbkrztnwjpfmaq"
d = maketrans(a, b)
for i in xrange(n):
	print "Case #%d: %s" % (i + 1, raw_input().translate(d))
