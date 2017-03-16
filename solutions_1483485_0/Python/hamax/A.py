m = {'y':'a', 'e':'o', 'q':'z'}
a = 'ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv'
b = 'our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up'

for ca, cb in zip(a, b):
	m[ca] = cb

def get_missing(s):
	for i in range(ord('a'), ord('z') + 1):
		if chr(i) not in s:
			return chr(i)

m[get_missing(m)] = get_missing(set(v for k, v in m.iteritems()))

for i in range(int(raw_input())):
	print 'Case #%d: %s' % (i + 1, ''.join(m[c] for c in raw_input()))
