import math

def findNextLarge(array,me):
	for i in range(len(array)):
		if array[i] > me:
			return i

def data(filename):
	f = open(filename,'r')
	S = f.read()
	f.close()
	A = S.splitlines()
	T = int(A[0])
	f = open(filename + ' output','w')
	for i in range(T):
		c = 0
		D = map(int,A[1+2*i].split())
		E = D[0]
		maxE = E
		R = min(E,D[1])
		N = D[2]
		maxlook = int(math.ceil((E*(1.0))/R) - 1)
		V = map(int,A[2+2*i].split())
		V += [0]*maxlook
		for j in range(N):
			if maxlook == 0:
				c += E*V[j]
				E = 0
			elif max(V[j:j+maxlook+1]) == V[j]:
				c += E*V[j]
				E = 0
			else:
				fm = findNextLarge(V[j:j+maxlook+1],V[j])
				surplus = min(E+fm*R-maxE,maxE)
				if surplus > 0:
					surplus = min(surplus,E)
					c += surplus*V[j]
					E -= surplus
			E += R
			E = min(E,maxE)
		f.write('Case #' + str(i+1) + ': ' + str(c) + '\n')
	f.close()