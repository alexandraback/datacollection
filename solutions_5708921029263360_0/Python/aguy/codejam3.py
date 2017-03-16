import itertools

def ans(j,p,s,k):
	x = f(j,p,s,k)
	ans = str(len(x)) + '\n'
	ans += printGrid(x)
	return ans

def printGrid(g):
	x = list(map(lambda x: ' '.join(map(str,x)),g))
	return '\n'.join(x)

def f(j,p,s,k):
	poss = []
	for a in range(1,j+1):
		for b in range(1, p + 1):
			for c in range(1,s+1):
				poss.append([a,b,c])
	for i in range(len(poss), 0,-1):
		for x in itertools.combinations(poss, i):
			if works(x,j,p,s,k):
				return x
	#return poss
	


def works(x, j, p, s, k):
	#print('hi',j,p,s)
	for a in range(1,j+1):
		for b in range(1,p+1):
			count = 0
			for i in x:
				if i[0] == a and i[1] == b:
					count += 1
			if count > k:
				return False
	for a in range(1,j+1):
		for c in range(1,s+1):
			count = 0
			for i in x:
				if i[0] == a and i[2] == c:
					count += 1
			if count > k:
				return False
	for b in range(1, p+1):
		for c in range(1,s+1):
			count = 0
			for i in x:
				if i[1] == b and i[2] == c:
					count += 1
			if count > k:
				return False
	return True

n = int(input())
for i in range(n):
	x = ans(*map(int,input().split()))
	print("Case #{0}: {1}".format(i+1, x))