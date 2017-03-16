from string import maketrans

table = maketrans(
    'ynficwlbkuomxsevqpdrjgthaz',
    'abcdefghijklmnopzrstuvwxyq',
)

n = int(raw_input())
for i in xrange(1, n + 1):
    line = raw_input()
    print 'Case #%d:' % i, line.translate(table)
