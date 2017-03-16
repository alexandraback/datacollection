import itertools
import sys

maxn = 2000000

checked = set()
ans_leq = []

def genans(n):
	strn = str(n)
	if len(strn)<=1 or n in checked:
		return
	res = [n]
	strn2 = strn[1:] + strn[0]
	while strn2 != strn:
		if strn2[0]!='0':	
			n2 = int(strn2)
			#if n2==12:
			#	print strn2, n2, strn, n
			if n2<=maxn:
				res.append(n2)
			checked.add(n2)
		strn2 = strn2[1:] + strn2[0]
	if len(res)>1:
		ans_leq.append(res)

for i in range(maxn+1):
	genans(i)
	
# print ans_leq

with open(sys.argv[1], 'r') as input:
	n = int(input.readline())
	for i in range(n):
		n, m = map(int, input.readline().rstrip().split())
		ans = 0
		for l in ans_leq:
			c = len(filter(lambda z: n<=z<=m, l))
			ans += c * (c-1) / 2
		print 'Case #{}: {}'.format(i+1, ans)
		