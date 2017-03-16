f = open('input.dat', 'r')
out = open('4.out', 'w')

nb = int(f.readline())

def getline(file):
	line = f.readline()
	line = line.replace("\n", '')
	line = line.replace(' ', ',')
	L = eval('['+line+']')
	return L

def impossible(val,L,C):
	res = 0
	for l in range(len(L)):
		if L[l]>val:
			res = res + 1
			break
	for l in range(len(C)):
		if C[l]>val:
			res = res + 1
			break
	if res == 2:
		return 1
	return 0

for i in range(nb):
	
	n, m = getline(f)
	M=[0 for j in range(n)]
	MT=[0 for k in range(m)]
	for j in range(n):
		M[j] = getline(f)
	for k in range(m):
		MT[k] = [M[j][k] for j in range(n)]
	
	status = 1
	for j in range(n):
		for k in range(m):
			#print(j,k,impossible(M[j][k], M[j], MT[k]))
			if impossible(M[j][k], M[j], MT[k]):
				status=0
				break
		if status==0:
			break

	if status==0:
		out.write("Case #%d: NO\n"%(i+1,))
	else:
		out.write("Case #%d: YES\n"%(i+1,))

out.write("\n")
out.close()



