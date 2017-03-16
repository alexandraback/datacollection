i,j,k = 2,3,4
mul = [[1,i,j,k],[i,-1,k,-j],[j,-k,-1,i],[k,j,-i,-1]]
dict = {'i': 2, 'j': 3, 'k': 4}

def run(s, x):
	n = 1
	for l in xrange(len(s)):
		n = mul[n - 1][dict[s[l]] - 1] if n > 0 else -mul[-n - 1][dict[s[l]] - 1]
		if n == x:
			return s[l + 1:]
	assert(False)

T = input()
for t in range(1, T + 1):
	l, x = [int(x) for x in raw_input().split()]
	s = raw_input()
	s = s * (8 + (x % 4)) if x > 11 else s * x
	ans = "NO"
	try:
		s = run(s, i)
		s = run(s, j)
		n = 1
		for l in s:
			n = mul[n - 1][dict[l] - 1] if n > 0 else -mul[-n - 1][dict[l] - 1]
		if n == k:
			ans = "YES"
	except:
		pass
	print "Case #%d: %s" % (t, ans)