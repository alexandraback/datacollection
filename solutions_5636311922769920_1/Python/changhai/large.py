#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def solve(K,C,S):
	need = (K-1)//C + 1
	if need > S:
		return "IMPOSSIBLE"
	rt = []
	pr("need", need)
	for i in range(need):
		x = 0
		for b in range(i*C, (i+1)*C):
			if b >= K: break
			x = x * K + b
		rt.append(x+1)
	return " ".join(str(x) for x in rt)
	
def gen(a, c):
	rt = a
	for i in range(c-1):
		xx = ""
		for x in rt:
			if x=='L':
				xx += a
			else:
				xx += 'G' * len(a)
		rt = xx
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

all = ["GGG", "GGL", "GLG", "GLL", "LGG", "LGL", "LLG", "LLL"]

out.close()