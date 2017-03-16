T = input()

def somefunc(N,M):
	if len(N) == 0 or len(M) == 0: return 0
	value = 0
	if N[1] == M[1]:
		if N[0] < M[0]:
			M[0] -= N[0]
			value = N[0]
			N.pop(0)
			N.pop(0)
		elif M[0] < N[0]:
			N[0] -= M[0]
			value = M[0]
			M.pop(0)
			M.pop(0)
		else:
			value = N[0]
			N.pop(0)
			N.pop(0)
			M.pop(0)
			M.pop(0)
		return value + somefunc(list(N),list(M))
	else:
		value = 0
		copyN1 = list(N)
		copyN2 = list(N)
		copyM1 = list(M)
		copyM2 = list(M)
		copyN1.pop(0)
		copyN1.pop(0)
		copyM2.pop(0)
		copyM2.pop(0)
		return max(somefunc(copyN1,copyM1),somefunc(copyN2,copyM2))


for t in range(T):
	data = raw_input()
	
	data = raw_input().split()
	Nlist = [int(i) for i in data]
	data = raw_input().split()
	Mlist = [int(i) for i in data]

	print("Case #%d: %d" % (t+1,somefunc(list(Nlist),list(Mlist))))