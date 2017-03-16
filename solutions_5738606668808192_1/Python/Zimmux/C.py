import fileinput
stdin = fileinput.input()

PP = 1000000
P = [True]*PP
P[0] = False
P[1] = False
i = 2
while i*i<PP:
	if not P[i]:
		i += 1
		continue
	j = i*i
	while j<PP:
		P[j] = False
		j += i
	i += 1
P = [i for i,p in enumerate(P) if p]

def test(n):
	B = [int(str(n),i) for i in range(2,10+1)]
	proof = [n]
	for b in B:
		d = 0
		for p in P:
			if p>=b:
				break
			if b%p==0:
				d = p
				break
		if d==0:
			break
		proof.append(d)
	if d:
		yield proof

def explore(n,i,N):
	if i>=N-1:
		for proof in test(n):
			yield proof
	else:
		for proof in explore(n,i+1,N):
			yield proof
		for proof in explore(n+10**i,i+1,N):
			yield proof

def certs(N,J):
	x = explore(10**(N-1)+1,2,N)
	return [next(x) for _ in range(J)]

def solveCase():
	N,J = map(int,next(stdin).split())
	return ''.join('\n'+' '.join(map(str,c)) for c in certs(N,J))

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))