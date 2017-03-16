#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def solve(cakes):
	segs = 1
	for i in range(1, len(cakes)):
		if cakes[i] != cakes[i-1]:
			segs += 1
	if cakes[-1] == "-":
		return segs
	else:
		return segs - 1
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	cakes = f.readline().strip()
	pr(cakes)
	rt = solve(cakes)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()