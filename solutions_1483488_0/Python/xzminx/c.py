import sys

def pairs(aa, b):
	m = set()
	a = str(aa)
	for i in range(1, len(a)):
		if a[i] < a[0]: continue
		s = a[i:] + a[:i]
		if s > a and int(s) <= b:
			m.add(int(s))
	return m

memo = {}

def solve(a, b):
	cnt = 0
	for i in range(a, b+1):
		for pair in memo[i]:
			if pair <= b:
				cnt += 1
	return cnt

def calculate():
	for i in range(1, 2000001):
		memo[i] = pairs(i, 2000000)
		
if __name__ == '__main__':
	fin = sys.stdin
	if len(sys.argv) > 1:
		fn = sys.argv[1]
		if fn != '-':
			fin = open(fn)
			
	calculate()
			
	fout = open('c.out', 'w')
	t = int(fin.readline())
	for i in range(t):
		g = fin.readline().strip().split(' ')
		a = int(g[0])
		b = int(g[1])
		ss = 'Case #%d:'%(i+1) + ' ' + str(solve(a,b))
		print ss
		fout.write(ss+'\n')
	fin.close()
	fout.close()

