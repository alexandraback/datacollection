import sys
inp = """4
1 9
10 40
100 500
1111 2222"""
if len(sys.argv) > 1:
	inp = open(sys.argv[1]).read().strip()

def recycle(n,mn=None,mx=None):
	sn = str(n)
	n = int(n)
	out = []
	for i in xrange(1, len(sn)):
		x = sn[:i]
		o = sn[i:]
		m = int(o+x)
		if mx and m > mx:
			continue
		if mn and m < mn:
			continue
		if m > n and m not in out:
			out.append(m)
	return len(out)

for ln,i in enumerate(inp.split("\n")[1:]):
	i = i.split(" ")
	out = 0
	for y in xrange(int(i[0]), int(i[1])):
		out += recycle(y, int(i[0]), int(i[1]))
	print "Case #%s: %s"%(ln+1, out)