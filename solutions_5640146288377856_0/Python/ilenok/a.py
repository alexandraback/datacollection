def ceildiv(a, b):
	if (a % b == 0):
		return a / b
	else:
		return a / b + 1
	
def brattleship(r, c, w):
	tmp = (c / w) * r
	if (c % w == 0):
		return  tmp + (w - 1)
	else:
		return tmp + w
	

inf = open("a.in", 'r')
outf = open("a.out", 'w')



t = int(inf.readline())

for k in xrange(0, t):
	r, c, w = map(int, inf.readline().split())		
	outf.write("Case #" + str(k + 1) + ": ")	
	outf.write(str(brattleship(r, c, w)) + "\n")
outf.close()
