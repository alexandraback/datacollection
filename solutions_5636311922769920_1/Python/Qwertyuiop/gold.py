def run(K,C,S):
	index = bootstrap(K,C)
	if len(index)>S: return "IMPOSSIBLE"
	return " ".join(index)

def bootstrap(K,C):
	cov=[((i,),i) for i in range(K)]
	cov = rec(cov,K,C-1)
	return find_index(cov, K)
def rec(cov, K, C):
	if C==0 or len(cov[0][0])==K:
		return cov
	new_cov = []
	for covering in cov:
		for new_val in range(covering[0][-1]+1,min(K,covering[0][-1]+2)):
			new_vals = covering[0] + (new_val,)
			new_index = covering[1]*K + new_val
			new_cov.append((new_vals, new_index))
	print new_cov
	return rec(new_cov, K, C-1)

def find_index(cov,K):
	ind=[]
	i=0
	target=0
	while i<len(cov)-1 and target<K:
		if cov[i][0][0]>target: raise Exception()
		if cov[i][0][0]==target:
			target=cov[i][0][-1]+1
			ind.append(str(cov[i][1]+1))
		i+=1
	if target<K:
		v = cov[-1][0]
		if target<v[0] and K-1>v[-1]: raise Exception("")
		ind.append(str(cov[-1][1]+1))
	return ind
import sys
f=open(sys.argv[1], "r")
F=open(sys.argv[1]+"out", "w")
f.readline()
L = f.readlines()
for i in range(len(L)):
	line = L[i].rstrip()
	vals=map(int, line.split(" "))
	F.write("Case #")
	F.write(str(i+1))
	F.write(": ")
	F.write(run(*vals))
	F.write("\n")
			
	
