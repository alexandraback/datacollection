# Counting Sheep.py

from collections import defaultdict

def update(n):
	for ch in str(n):
		d[ch] = 1;

t = int(raw_input())
for x in xrange(1,t+1):
	n = int(raw_input())
	if n == 0 :
		ans = 'INSOMNIA'
	else:
		d = defaultdict(int)
		i = 2;
		f = n;
		while sum(d.values()) < 10 :
			update(n);
			ans = n;
			n = n+f;
			i += 1;
			# print d.items(),n;
	print 'Case #'+str(x)+':',str(ans);