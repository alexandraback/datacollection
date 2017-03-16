import sys

base = ['ejp mysljylc kd kxveddknmc re jsicpdrysi', 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'de kr kd eoya kw aej tysr re ujdr lkgc jv']
rest = ['our language is impossible to understand', 'there are twenty six factorial possibilities', 'so it is okay if you want to just give up']
coding = dict()
coding['q'] = 'z'
coding['z'] = 'q'

n = len(base)

for i in range(n) :
	m = len(base[i])
	for j in range(m) :
		coding[base[i][j]] = rest[i][j]

t = int(sys.stdin.readline())

for i in range(t) :
	line = sys.stdin.readline().strip()
	x = [coding[c] for c in line]

	print "Case #%d:"%(i+1), "".join(x)