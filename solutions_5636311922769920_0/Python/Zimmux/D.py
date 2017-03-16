import fileinput
stdin = fileinput.input()

def solveCase():
	K,C,S = map(int,next(stdin).split())
	if S*C<K:
		return 'IMPOSSIBLE'
	i = 0
	g = []
	while i<K:
		p = 1
		for d in range(C):
			p += (min(i+d,K-1))*K**(C-1-d)
		g.append(p)
		i += C
	return ' '.join(map(str,g))

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))