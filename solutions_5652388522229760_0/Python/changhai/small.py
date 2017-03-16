#debug 
def pr(*a):
	#return
	for x in a: print x,
	print

def solve(a):
	if a == 0: return "INSOMNIA"
	remain = set([0,1,2,3,4,5,6,7,8,9])
	i = 0
	while 1:
		i += 1
		x = a * i
		while x > 0:
			r = x%10
			remain.discard(r)
			x /= 10
		if not remain:
			pr(i, a*i)
			return a * i
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	a = int(f.readline().strip())
	pr(a)
	rt = solve(a)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()