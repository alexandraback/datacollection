import sys

def sgn(n):
	if (n == 0): return 0
	return int(n / abs(n))

def P(Q, n, s, m):
	if (s >= 5 or 2 * n + (m == 1) > len(Q)): return 0

	r = 1
	if (2 * n + 1 + (m == 1) <= len(Q)):
		r += 1
		
		q = m if m else sgn(1 - int(Q[n]))
		if (2 * n + 1 + (q == 1) <= len(Q)): r += 1

		q = m if m else sgn(2 - int(Q[n]))
		if (s < 3 and 2 * n + 1 + (q == 1) <= len(Q)): r += 1

	for i in range(0, 3):
		r += P(Q, n + 1, s + i ** 2, m if m else sgn(i - int(Q[n])))

	return r

def ver(n):
	if (int(n) < 11): return min(3, int(n))

	s = str(n)
	d = len(s)

	h = s[:d // 2] + (s[d // 2] if d % 2 != 0 else '') + s[:d // 2][::-1] 
	if (int(h) > n):
		q = int(s[:d // 2 + d % 2]) - 1
		h = str(q) + str(q)[:d // 2][::-1]

	# print ('Usa el valor: ' + h + ' para ' + str(n))
	return 3 + P(h, 1, 1, sgn(1 - int(h[0]))) + P(h, 1, 4, sgn(2 - int(h[0])))

def sqrti(a):
	n = 0
	m = a + 1

	while m - n > 1:
		s = (n + m) // 2
		
		if (s ** 2 <= a): n = s
		else: m = s
	
	return n

def caso():
	A, B = [int(x) for x in sys.stdin.readline().split()]
	return ver(sqrti(B)) - ver(sqrti(A - 1))

def main():
	t = int(sys.stdin.readline())
	for i in range(t):
		print('Case #{}: {}'.format(i + 1, caso()))

main()

