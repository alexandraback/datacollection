import string

n = input()
table = string.maketrans('abcdefghijklmnopqrstuvwxyz', 'yhesocvxduiglbkrztnwjpfmaq')
for i in xrange(n):
    s = raw_input()
    print "Case #%d: %s" % (i + 1, s.translate(table))
