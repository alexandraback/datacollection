import fileinput
stdin = fileinput.input()

def fmt(C,J):
	return ''.join(map(str,C))+' '+''.join(map(str,J))

def repl(C,df=0):
	return [d if d!=-1 else df for d in C]

def sumUp(C,df=0):
	s = 0
	for d in C:
		s *= 10
		s += d
	return s

def allPossible(C):
	done = False
	for i,d in enumerate(C):
		if d==-1:
			for j in range(10):
				D = list(C)
				D[i] = j
				for E in allPossible(D):
					yield E
			done = True
			break
	if not done:
		yield C

# min C-J
# min C
# min J
def solveCase():
	C,J = next(stdin).split()
	n = len(C)
	C = [int(d) if d!='?' else -1 for d in C]
	J = [int(d) if d!='?' else -1 for d in J]
	pC = list(allPossible(C))
	pJ = list(allPossible(J))
	sC = list(map(sumUp,pC))
	sJ = list(map(sumUp,pJ))

	bC,bsc,bJ,bsj = None,None,None,None
	for c,sc in zip(pC,sC):
		for j,sj in zip(pJ,sJ):
			if bC==None:
				bC,bsc,bJ,bsj=c,sc,j,sj
			else:
				if abs(sc-sj)<abs(bsc-bsj):
					bC,bsc,bJ,bsj=c,sc,j,sj
				elif abs(sc-sj)==abs(bsc-bsj):
					if sc<bsc:
						bC,bsc,bJ,bsj=c,sc,j,sj
					else:
						if sc==bsc and sj<bsj:
							bC,bsc,bJ,bsj=c,sc,j,sj
	return fmt(bC,bJ)

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))