f = open("b.in")
d = f.read().strip().split("\n")[1:]
f.close()

def ext(nint, ninp):
	s = str(nint)
	s = "0" * (len(ninp)-len(s)) + s
	return s

def matches(nint, ninp):
	s = ext(nint, ninp)
	for i in xrange(len(ninp)):
		if ninp[i] != "?" and ninp[i] != s[i]:
			return False
	return True

def posC(c):
	q = c.count("?")
	cs = []
	for i in xrange(10**q):
		d = list(c)
		for j in xrange(q):
			d[d.index("?")] = str((i / 10**j) % 10)
		cs.append(int("".join(d)))
	return cs
	"""
	if len(c) == 1:
		if c == "?": return [for i in xrange(10)]
		return int(c)
	if len(c) == 2:
		if c == "??": return [for i in xrange(100)]
		if c[0] == "?": return [for i*10+int(c[1]) in xrange(10)]
		if c[1] == "?": return [for int(c[1])*10+i in xrange(10)]
	
	if len(c) == 3:
		if c == "???": return [for i in xrange(1000)]
		
		if c[0] == "?" and c[1] == "?": return [i*10+int(c[2]) for i in xrange(100)]
		if c[1] == "?" and c[2] == "?": return [for i+int(c[0])*100 for i in xrange(100)]
		if c[0] == "?" and c[2] == "?": return [for i*10+int(c[2]) for i in xrange(10)]
		
		if c[0] == "?": return [for i*10+int(c[1]) in xrange(10)]
		if c[1] == "?": return [for int(c[1])*10+i in xrange(10)]
		if c[1] == "?": return [for int(c[1])*10+i in xrange(10)]
	"""

o = open("b.out", "w")
for i in xrange(len(d)):
	s = d[i].split(" ")
	
	l = len(s[0])
	
	best = (10000, 10000, 100000)
	
	for c in posC(s[0]):# xrange(0, 10**l):
		for j in posC(s[1]):
			#if matches(c, s[0]) and matches(j, s[1]):
			new = (abs(c-j), c, j)
			if new < best:
				best = new
			#if best: break
		#if best: break
	#if best: break
	
	ln = "Case #%d: %s %s" % (i + 1, ext(best[1], s[0]), ext(best[2], s[0]))
	
	print ln
	o.write(ln + "\n")
o.close()
