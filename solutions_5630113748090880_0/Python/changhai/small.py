#debug 
def pr(*a):
	#return
	for x in a: print x,
	print

def solve(N, papers):
	count = [0]*2501
	for p in papers:
		hs = p.split()
		for h in hs:
			count[int(h)] += 1
	rt = []
	for i in range(2501):
		if count[i] % 2:
			rt.append(i)
	assert len(rt) == N
	rt.sort()
	return " ".join(str(h) for h in rt)
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	N = int(f.readline().strip())
	papers = []
	for i in range(2*N-1):
		papers.append(f.readline().strip())
	print papers
	rt = solve(N, papers)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()