from sys import stdin

def solve(N, a, b):
	i = 0
	stars = 0
	result = 0
	done = [ 0 ] * N
	
	while True:
		while i < N and b[i][2] <= stars:
			stars += 2
			result += 1
			done[b[i][0]] = 2
			i += 1

		if i == N:
			break
		
		next = b[i][2]
		j = 0
		while j < N and a[j][1] <= stars and stars < next:
			if done[a[j][0]] == 0:
				stars += 1
				result += 1
				done[a[j][0]] = 1
			j += 1
		
		if stars < next:
			return None
			
	return result
	
def program():
	T = int(stdin.readline())
	for Ti in xrange(T):
		N = int(stdin.readline())
		ab = []
		for Ni in xrange(N):
			ai, bi = map(int, stdin.readline().rstrip().split(' '))
			ab.append(( Ni, ai, bi ))
		
		b = sorted(ab, key=lambda x: x[2])
		a = sorted(b, key=lambda x: x[1])
			
		r = solve(N, a, b)
		
		if r is not None:
			print 'Case #%d: %d' % (Ti + 1, r)
		else:
			print 'Case #%d: Too Bad' % (Ti + 1)
	
if __name__ == '__main__':
	program()