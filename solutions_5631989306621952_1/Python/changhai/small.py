#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def solve(S):
	rt = S[0]
	for i in range(1, len(S)):
		if S[i] >= rt[0]:
			rt = S[i] + rt
		else:
			rt += S[i]
	return rt

	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	S = f.readline().strip()
	rt = solve(S)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()