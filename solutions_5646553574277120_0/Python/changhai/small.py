#debug 
def pr(*a):
	#return
	for x in a: print x,
	print

def solve(C,ds,V):
	vs = [0]*(V+1)
	vs[0] = 1
	for d in ds:
		if d > V: continue
		for x in range(V, d-1, -1):
			if vs[x-d]:
				vs[x] = 1
	newd = 0
	for d in range(V+1):
		if vs[d]: continue
		newd += 1
		for x in range(V, d-1, -1):
			if vs[x-d]:
				vs[x] = 1
	return newd

import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	C,D,V = [int(x) for x in f.readline().strip().split()]
	pr(C,D,V)
	ds = [int(x) for x in f.readline().strip().split()]
	pr(ds)
	assert len(ds)==D
	rt = solve(C,ds,V)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()