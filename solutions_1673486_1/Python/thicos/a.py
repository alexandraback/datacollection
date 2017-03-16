Tc = input()

for T in range(1, Tc+1):
	sin = raw_input().split()
	A = int(sin[0])
	B = int(sin[1])
	sin = raw_input().split()
	vet = []
	aVet = []
	for i in range(0, A):
		vet.append(float(sin[i]))
		if (i == 0):
			aVet.append(vet[i])
		else:
			aVet.append(vet[i]*aVet[i-1])
	henter = 2+B
	finish = aVet[A-1]*(B-A+1)+(1-aVet[A-1])*(2*B-A+2)
	mi	= henter
	for i in range(0, A):
		er = (2*i+B-A+1)
		ew = (2*i+2*B-A+2)
		p = aVet[A-i-1]
		q = 1 - p
		
		v = p*er + q*ew
		#print('v: %f i: %f p: %f q: %f er: %f ew: %f' % (v,i,p,q,er,ew))
		if (v < mi): 
			mi = v
			
	#print ('%f %f %f' % (henter, mi, finish))
	mi = min(mi, henter, finish)
	print('Case #%d: %f' % (T, mi)) 
			