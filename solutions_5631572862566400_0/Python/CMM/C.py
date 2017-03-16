import itertools


def test(bff, perm):
	for i in range(len(perm)):
		prev = i - 1
		nxt = i + 1
		if nxt == len(perm): nxt = 0
		
		if bff[perm[i]] == perm[nxt] or bff[perm[i]] == perm[prev]:
			pass
		else:
			return False
		
		
	return True
			
def solve(bff):
	for L in range(len(bff), 1, -1):
		for i in itertools.combinations(range(len(bff)), L):
			for j in itertools.permutations(i):
				if test(bff, j):
					return L
	return -1
				
	
N = int(raw_input())

case = 1
for i in range(N):
	n = int(raw_input())
	z = [int(j)-1 for j in raw_input().split()]

	print ("Case #%d:" % case), solve(z)
	case += 1
