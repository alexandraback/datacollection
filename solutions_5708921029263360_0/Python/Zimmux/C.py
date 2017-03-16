from collections import deque,defaultdict
import fileinput
stdin = fileinput.input()

def brute(combos,ps,js,jp,sol,bst):
	if len(sol)>len(bst):
		bst = sol
	if len(sol)+len(combos)>len(bst):
		if combos:
			j,p,s = combos[0]
			bst = brute(combos[1:],ps,js,jp,sol,bst)
			if ps[(p,s)]>0 and js[(j,s)]>0 and jp[(j,p)]>0:
				ps[(p,s)] -= 1
				jp[(j,p)] -= 1
				js[(j,s)] -= 1
				bst = brute(combos[1:],ps,js,jp,sol+[(j,p,s)],bst)
				ps[(p,s)] += 1
				jp[(j,p)] += 1
				js[(j,s)] += 1
	return bst

def solveCase():
	J,P,S,K = list(map(int,next(stdin).split()))
	combos = [ (j,p,s) for j in range(J) for p in range(P) for s in range(S)]
	ps = defaultdict(lambda:K)
	js = defaultdict(lambda:K)
	jp = defaultdict(lambda:K)
	O = brute(combos,ps,js,jp,[],[])
	return str(len(O))+'\n'+'\n'.join(' '.join(str(i+1) for i in o) for o in O)

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))