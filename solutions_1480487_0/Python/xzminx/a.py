import sys

def solve(n, pts):
	suma = 0
	sol = []
	for p in pts:
		suma += p
	b = sorted(pts)
	for p in pts:
		used = 0
		left = suma
		for i in range(len(b)):
			other = b[i]
			count = abs(p - other)
			if other < p:
				if left <= count:
					left = 0
					break
				left -= count
			elif other >= p:
				if left < i * count:
					used += left / float(i)
					left = 0
					break
				used += count
				left -= i * count
				p = other
		if left > 0:
			used += left / len(pts)
		sol.append(used / suma)	
			
	ss = ''
	for i in range(len(sol)):
		if i > 0:
			ss += ' '
		ss += str(100 * sol[i])	
	return ss
	
	
if __name__ == '__main__':
	fin = sys.stdin
	if len(sys.argv) > 1:
		fn = sys.argv[1]
		if fn != '-':
			fin = open(fn)
	fout = open('a.out', 'w')
	t = int(fin.readline())
	for i in range(t):
		g = fin.readline().strip().split(' ')
		g = [float(k) for k in g]
		ss = 'Case #%d:'%(i+1) + ' ' + solve(g[0], g[1:])
		print ss
		fout.write(ss+'\n')
	fout.close()
