import fileinput
from itertools import permutations

def check(n, m, e, p):
	v = p[0]
	s = [v]
	for w in p[1:]:
		while (v, w) not in e:
			if not s: return False
			v = s.pop()
		s.append(w)
		v = w
	return True

def solve(n, m, codes, e):
	codes.sort()
	for x in permutations(codes):
		if check(n, m, e, [p[1] for p in x]): return "".join(str(p[0]) for p in x)
	return "?"

f = fileinput.input()
tt = int(f.readline())
for t in range(tt):
	n, m = list(map(int, f.readline().rstrip().split()))
	codes = [(int(f.readline()), i) for i in range(n)]
	e = []
	for _ in range(m):
		x, y = tuple(map(int, f.readline().rstrip().split()))
		e.append((x-1, y-1))
		e.append((y-1, x-1))
	print("Case #%d:" % (t+1), solve(n, m, codes, e))