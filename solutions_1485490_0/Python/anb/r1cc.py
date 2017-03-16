from sys import stdin

def check(a, t, P, j):
	jj = j
	m = 0
	while jj < len(P):
		if P[jj + 1] == t:
			c = min(a, P[jj])
			a -= c
			m += c
		jj += 2
	return m

def calc(A, B, i, j):
	A = list(A)
	B = list(B)
	if i == len(A) - 2:
		return check(A[i], A[i + 1], B, j)
	elif j == len(B) - 2:
		return check(B[j], B[j + 1], A, i)
	elif A[i + 1] == B[j + 1]:
		m = min(A[i], B[j])
		A[i] -= m
		B[j] -= m
		if A[i] == 0:
			i += 2
		if B[j] == 0:
			j += 2
		return m + calc(A, B, i, j)
	else:
		ca = calc(A, B, i + 2, j)
		cb = calc(A, B, i, j + 2)
		return max(ca, cb)

def main():
	T = int(stdin.readline())
	for Ti in xrange(T):
		N, M = map(int, stdin.readline().rstrip().split(' '))
		A = map(int, stdin.readline().rstrip().split(' '))
		B = map(int, stdin.readline().rstrip().split(' '))
		
		count = calc(A, B, 0, 0)
		
		print 'Case #%d: %d' % (Ti + 1, count)
		
if __name__ == '__main__':
	main()