
def solve_brute_force(A, B, K):
	count = 0
	for a in range(A):
		for b in range(B):
			if a & b < K:
				count += 1

	return count

def solve_all(testid):
	inputfile = testid + '.in'
	outputfile = testid + '.out'

	f = open(inputfile)
	g = open(outputfile, 'w')

	T = int(f.readline())

	for t in range(T):
		print(t)
		(A,B,K) = [int(x) for x in f.readline().split()]
		count = solve_brute_force(A,B,K)
		g.write('Case #{}: {}\n'.format(t+1, count))

	f.close()
	g.close()

if __name__ == '__main__':
#	solve_all('sample')
#	solve_all('test')
	solve_all('B-small-attempt0')
