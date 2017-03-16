import itertools
from bisect import *

a = set()
a.add(3)
for i in xrange(2, 10000):
	x = i / 2
	v = list()
	while x:
		v.append(x % 3)
		x /= 3
	v.reverse()
	for j in range(len(v) - (i % 2), 0, -1):
		v.append(v[j - 1])
	n = 0
	for x in v:
		n *= 10
		n += x
	s = str(n * n)
	if s != s[::-1]:
		continue
	a.add(n)

for l in range(2, 60):
	a.add(10 ** l * 2 + 2);
	if l % 2:
		a.add(10 ** (l - 1) * 2 + 10 ** ((l - 1) / 2) + 2);

for l in range(13, 60):
	for c in range(0, 4):
		for p in itertools.combinations(range(l / 2), c):
			x = 0
			for i in p:
				x += 10 ** i + 10 ** (l - i - 1)
			x += 10 ** l
			x *= 10
			x += 1
			
			for m in range(3 if l % 2 else 1):
				n = x + m * (10 ** ((l - 1) / 2 + 1))
				s = str(n * n)
				if s != s[::-1]:
					continue
				a.add(n)

l = list(a)
l.sort()
s = [x ** 2 for x in l]
with open("py", "w") as f:
	for n in s:
		f.write("%d\n" % n)
		
with open("in", "r") as fin:
	with open("out", "w") as fout:
		for t in range(int(fin.readline())):
			fout.write("Case #%d: " % (t + 1))
			a, b = map(long, fin.readline().split())
			fout.write("%d\n" % (bisect_right(s, b) - bisect_left(s, a)))
