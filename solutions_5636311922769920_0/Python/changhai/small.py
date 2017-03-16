#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def solve(K,C,S):
	rt = "1"
	for i in range(1, K):
		rt += " " + str(1+K**(C-1)*i)
	return rt
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	K, C, S = f.readline().strip().split()
	K, C, S = int(K), int(C), int(S)
	rt = solve(K,C,S)
	pr(K,C,S)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()