def allstrings(alphabet, length):
	"""Find the list of all strings of 'alphabet' of length 'length'"""
	
	if length == 0: return []
	
	c = [[a] for a in alphabet[:]]
	if length == 1: return c
	
	c = [[x,y] for x in alphabet for y in alphabet]
	if length == 2: return c
	
	for l in range(2, length):
		c = [[x]+y for x in alphabet for y in c]
	# x = c
	# seen = set()
 #   seen_add = seen.add()
 #   return [ x for x in seq if not (x in seen or seen_add(x))]
	return c

if __name__ == "__main__":
	t = int(raw_input())
	for i in range(1, t+1):
		inp = map(int, raw_input().split(' '))
		k = inp[0]
		l = inp[1]
		s = inp[2]
		word = raw_input()
		L = allstrings(list(word), s)
		ans = 0
		total = len(L)
		word = raw_input()
		m = -1
		for w in L:
			st = ''.join(w)
			m = max(st.count(word), m)
			ans += st.count(word)
		ans = float(ans)/total
		ans -= m
		if (ans != 0): ans *= -1
		print "Case #%d: %.7f" % (i, ans)
