t = int(raw_input())

def test(T):
	k,c,s = map(int,raw_input().split())
	K = range(k)
	A = []
	x = 0
	lvl = 0
	for e in K:
		x = x*k+e
		lvl += 1
		if c == lvl:
			A.append(x)
			x = 0
			lvl = 0
	print 'Case #%d: '%T,
	while lvl != c:
		x = x*k
		lvl += 1
	if x != 0 or len(A) == 0:
		A.append(x)
	if len(A) > s:
		print 'IMPOSSIBLE'
		return
	for a in map(lambda x:x+1,A):
		print a,
	print ''

for i in range(1,t+1):
	test(i)
