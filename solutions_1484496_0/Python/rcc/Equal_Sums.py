#Ricardo Corral Corral - mayo 5, 2012
import sys



fin = open(sys.argv[1])

N = int(fin.readline().strip())
D = {}

for i in xrange(1,N+1):
	D.clear()
	linea = fin.readline()
	L = map(int,linea.strip().split())
	N = int(L[0])
	S = L[1:]
	sepudo = False
	for j in xrange(1,2**N):
		suma = 0
		local = list()
		for k in xrange(0,20):
			if j&(1<<k):
				local.append(str(S[k]))
				suma += S[k]
		if suma in D:
			sepudo = True
			print 'Case #'+str(i)+':\n' + ' '.join(D[suma]) + '\n' + ' '.join(sorted(local))		
			break	
		else:
			D[suma] = sorted(local)
	if not sepudo:
		print 'Case #'+str(i)+':\nImpossible'
