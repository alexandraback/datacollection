import sys
import collections

in_file = "A-small"
sys.stdin = open(in_file+".in")
sys.stdout = open(in_file+".out","w")

ntc = int(input())

for tc in range(ntc):
	x = input().strip()
	dd=["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	d = dict()
	for c in x:
		if c in d: d[c] += 1
		else: d[c] = 1
	
	
	ans = []
	
	q = [(0,'Z'), (4,'U'),  (3,'R'), (8,'H'), (2,'T'), (1,'O'), (6,'X'), (5,'F'), (7,'V'), (9,'N')]
	for n,x in q:
		if x in d:
			while d[x]:
				for c in dd[n]: d[c]-=1
				ans.append(n)
	ans.sort()
	assert(sum(d[x] for x in d)==0)
	
	print('Case #%d: '%(tc+1) + ''.join(str(x) for x in ans))
