#from sys import stdin as fin, stdout as fout
fin = open('input.txt'); fout = open('output.txt','w')
get = lambda: map(int,fin.readline().split())

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache: cache[args] = f(*args)
		return cache[args]
	return wrap


T, = get()

for case in range(1,T+1):

	A,N = get()
	s = sorted(get(), reverse=True)

	while s and A > s[-1]:
		A += s.pop()

	if not s:
		fout.write('Case #%d: 0\n' % case)
		continue

	s = s[::-1]
	N = len(s)

	@memo
	def steps(n,a,start):
		if a == 1: return n
		if start == n: return 0
		if n == 0: return 0
		req = steps(n-1,a,start)+1
		a += a-1
		while start < n and a > s[start]:
			a += s[start]
			start += 1
		return min(req,steps(n,a,start)+1)

	fout.write('Case #%d: %d\n' % (case,steps(N,A,0)))

