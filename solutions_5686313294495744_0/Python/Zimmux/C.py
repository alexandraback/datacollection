from collections import deque,defaultdict
import fileinput
stdin = fileinput.input()

def edge(a,b):
	return (min(a,b),max(a,b))

def alt(EE,M,s,U):
	q = deque()
	q.append((s,[]))
	while q:
		v,path = q.pop()
		for t in EE[v]:
			e = edge(v,t)
			if t in U and len(path)%2==1: # found path, return
				return path+[e]
			if len(path)%2==1:
				if e not in M:
					q.append((t,path+[e]))
			else:
				if e in M:
					q.append((t,path+[e]))
	return None
			

def solveCase():
	N = int(next(stdin))
	FS = [list(next(stdin).split()) for _ in range(N)]
	F = [f for f,s in FS]
	S = [s for f,s in FS]
	nf = 0
	DF = dict()
	for w in F:
		if w not in DF:
			DF[w] = nf
			nf += 1
	ns = 0
	DS = dict()
	for w in S:
		if w not in DS:
			DS[w] = nf+ns
			ns += 1
	F = [DF[w] for w in F]
	S = [DS[w] for w in S]
	L = set(range(nf))
	R = set(range(ns))
	EE = defaultdict(list)
	for l,r in zip(F,S):
		EE[l].append(r)
		EE[r].append(l)
	M = set()
	U = set(L)|set(R)
	todo = list(U)
	for v in todo:
		if v in U:
			P = alt(EE,M,v,U)
			if P!=None:
				for e in P:
					if e in M:
						M.remove(e)
					else:
						M.add(e)
					if e[0] in U:
						U.remove(e[0])
					if e[1] in U:
						U.remove(e[1])
	return N-len(M)-len(U)

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))