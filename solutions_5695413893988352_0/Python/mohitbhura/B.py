# B.py

from collections import defaultdict 

def solve(a,b,i):

	if i == len(a) :
		# print a,b
		a = int(''.join(map(str,a)))
		b = int(''.join(map(str,b)))
		d[abs(a-b)].append([a,b])
		return;

	if a[i] == '?' and b[i] == '?':
		for x in xrange(10):			
			for y in xrange(10):
				a[i] = x;
				b[i] = y;
				solve(a,b,i+1)
				a[i] = '?'
				b[i] = '?'
	elif a[i] == '?':		
		for x in xrange(10):
			a[i] = x;
			solve(a,b,i+1)
			a[i] = '?'
	elif b[i] == '?':		
		for x in xrange(10):
			b[i] = x;
			solve(a,b,i+1)
			b[i] = '?'
	else :
		solve(a,b,i+1)


t = int(raw_input())
for _ in xrange(t):
	d = defaultdict(list)
	print 'Case #'+str(_+1)+":",
	c,j = raw_input().split()
	a,b = list(c),list(j)
	ans = 0;
	solve(a,b,0)
	m = min(d.keys())
	arr = d[m]
	arr = sorted(arr)
	arr.sort()
	# print arr
	print str(arr[0][0]).zfill(len(c)),str(arr[0][1]).zfill(len(j));