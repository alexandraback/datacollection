dic = {}


def learn(a, b):
	assert len(a) == len(b)
	for i in range(len(a)):
		dic[a[i]] = b[i]


learn("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand")
learn("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities")
learn("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up")
learn("zq ", "qz ")

# solve
def decrypt(s):
	return ''.join([dic[c] for c in s])
		
n = input()
for i in range(n):
	print 'Case #%d: %s' % (i+1, decrypt(raw_input()))
