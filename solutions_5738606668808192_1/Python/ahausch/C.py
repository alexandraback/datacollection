import itertools
import sys

def asBase(a, b):
	s = 0
	e = 1;
	for i in range(len(a)):
		if (a[-1 - i] == 1):
			s += e
		e *= b
	return s

def lazyHasDivisor(v):
	for p in [2, 3, 5, 7, 11]:
		if (v % p == 0):
			return p
	return False

def solve(N, J):
    c = itertools.product(range(2), repeat=N-2)
    j = 0

    while (j < J):
        a = [1] + list(next(c)) + [1]
        p = [lazyHasDivisor(asBase(a, b)) for b in range(2, 11)]
        
        if (all(p)):
            j = j + 1
            print(''.join(str(i) for i in a), ' '.join(str(i) for i in p))


fin = open(len(sys.argv) > 1 and sys.argv[1] or 'test.in', 'r')

T = int(fin.readline())

for t in range(1, T + 1):
    (N, J) = map(int, fin.readline().split())
    print("Case #{0}:".format(t))
    solve(N, J)

fin.close()

