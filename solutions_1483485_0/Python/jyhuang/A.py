n = input()
tr = ''.join([chr(x) for x in range(256)]).replace('abcdefghijklmnopqrstuvwxyz', 'yhesocvxduiglbkrztnwjpfmaq')
for i in xrange(n):
	print "Case #{0}: {1}".format(i + 1, raw_input().translate(tr))
