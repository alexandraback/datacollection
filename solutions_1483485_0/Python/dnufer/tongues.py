import string

f = open('A-small-attempt0.in')
lines = [line.strip() for line in f.readlines()[1:]]
f.close()

froms = 'ynficwlbkuomxsevzpdrjgthaq'
to    = 'abcdefghijklmnopqrstuvwxyz'
trans = string.maketrans(froms, to)

for i, line in enumerate(lines):
	print 'Case #%d: %s' % ((i + 1), string.translate(line, trans))
