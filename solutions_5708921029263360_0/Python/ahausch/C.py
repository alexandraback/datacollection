import sys
import itertools

fin = open(sys.argv[1], 'r') if len(sys.argv) > 1 else sys.stdin

T = int(fin.readline())

for t in range(1, T + 1):
	J, P, S, K = map(int, fin.readline().split(' '))
	'''
	JP = dict((p, K) for p in itertools.product(range(J), range(P)))
	JS = dict((p, K) for p in itertools.product(range(J), range(S)))
	PS = dict((p, K) for p in itertools.product(range(P), range(S)))
	
	while JS:
		js = JS.pop(0)
		while 
	'''
	
	JP = [[K] * P for _ in range(J)]
	JS = [[K] * S for _ in range(J)]
	PS = [[K] * S for _ in range(P)]
	
	solutions = []
	
	for j in range(J):
		for p in range(P):
			for s in range(S):
				if JP[j][p] > 0 and JS[j][s] > 0 and PS[p][s] > 0:
					JP[j][p] -= 1
					JS[j][s] -= 1
					PS[j][s] -= 1
					
					# print("{} {} {}".format(j + 1, p + 1, s + 1))
					solutions.append((j, p, s))
					
	print("Case #{0}: {1}".format(t, len(solutions)))
	for s in solutions:
		print('{0} {1} {2}'.format(s[0] + 1, s[1] + 1, s[2] + 1))