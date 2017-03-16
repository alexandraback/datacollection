#with open("small-practice.in") as f:
with open("D-small-attempt4.in") as f:
#with open("D-large.in") as f:
	dat = f.read().splitlines()

def solution(K,C,S):
	sol = []
	n = (K-1)//C + 1
	
	if n>S:
		return ["IMPOSSIBLE"]
		
	for i in range(0,C*n,C):
		if K-i<C:
			i = K-C
		if i<0:
			i = 0
		id = i
		for j in range(1,C):
			if j>= K:
				j = K-1
			id = id*K + i + j 
		sol.append(id + 1)
	
	#if sol[-1]>K**C:
	#	sol[-1] = K**C - sol[0] + 1
	assert sol[-1]<=K**C
	assert sol.__len__() == set(sol).__len__()
	assert sol.__len__() == n
	return sol

def has_gold(i):
	return i.find("0")!=-1
def found_gold(sol,i):
	for s in sol:
		if i[s-1] == "0":
			return True
	return False
def test(K,C,S):
	sol = solution(K,C,S)
	for s in sol:
		if s<1:
			print(sol)
			input("Chyba")
	if K>25:
		#print('K too big')
		return False
	if K**C>10550:
		#print('K**C too big')
		return False
		
	if sol[0] == "IMPOSSIBLE":
		return True
	#print(sol)
	for i in range(2**K):
		i = str(bin(i))[2:]
		i = "0"*(K-i.__len__()) + i
		
		i0 = i
		for j in range(C-1):
			newi = ""
			for ii in list(i):
				if ii=="0":
					newi += "0"*K
				else:
					newi += i0
			i = newi
		
		if has_gold(i0) != found_gold(sol,i):
			print(i0)
			print(i)
			print(sol)
			input("CHYBA")
			return False
	return True
		
n = int(dat[0])
out = []
#outt = [str(n)]
n = dat.__len__()-1
for i in range(1,n+1):
	l = dat[i].split()
	K = int(l[0])
	C = int(l[1])
	S = int(l[2])
	
	#	A				B			C			D     1 + 2 + ..
	#A&A A&B A&C A&D B&A B&B B&C B&D C&A C&B C&C C&D D&A D&B D&C D&D    2 + 12 + ..
	#AAA AAB AAC AAD  ABA ABB ABC ABD							7 + ..
	
	sol = solution(K,C,S)
	#tested = test(K,C,S)
	#if not tested:
	#	outt.append(str(K)+" "+str(C)+" "+str(S))
	
	res = "Case #"+str(i)+": "+" ".join([str(s) for s in sol])

	print(res)
	out.append(res)

assert out.__len__() == n
of = open("out.txt","w")
of.write("\n".join(out))
of.close()
"""
of = open("small-practice.in","w")
of.write("\n".join(outt))
of.close()
"""
