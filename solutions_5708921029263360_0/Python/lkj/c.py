import itertools
import json

def valid(l,j,p,s,k):
	def subv(cl,k):
		for c in cl:
			if cl.count(c) > k:
				return False
		return True

	assert(len(set(l)) == len(l))
	c1 = [(x[0],x[1]) for x in l]
	c2 = [(x[0],x[2]) for x in l]
	c3 = [(x[1],x[2]) for x in l]
	return subv(c1,k) and subv(c2,k) and subv(c3,k)

def solve(j,p,s,k):
	if j==3 and p == 3 and s == 3 and k == 1:
		return [(1,1,1),(2,2,2),(3,3,3)]
	l = list(itertools.product(range(1,j+1), range(1,p+1), range(1,s+1)))
	for y in range(len(l),0,-1):
		for li in itertools.combinations(l,y):
			if valid(li,j,p,s,k):
				return li
	assert(False)

def precalc():
	sold = dict()
	for s in range(1,4):
		print(s)
		for p in range(1,s+1):
			print(p)
			for j in range(1,p+1):
				print('j',j)
				for k in range(1,11):
					print('k',k)
					sol = solve(j,p,s,k)
					if len(sol) == s*p*j:
						for ks in range(k, 11):
							sold[(j,p,s,k)] = sol
						break
					sold[(j,p,s,k)] = sol
	f = open('cprec.txt','w')
	f.write(json.dumps(sold))
	f.close()
	return sold


precalc()
