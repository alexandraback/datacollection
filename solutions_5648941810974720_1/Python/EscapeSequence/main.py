def solve(s):
	m = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 1], [1, 2, -2, -1, -2, 0, 0, 0,   3, -1], [0, 0, -1, 0, 0, 1, 0, 0, 0, 0], [0, -1, 1, 0, 0, 0, 0, 0,   0, 0], [0, 0, 0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 0, -1, 0, 0, 1, 1,   0], [0, 0, 0, 0, 0, 0, 0, 0, 1, 0], [0, 0, 0, 0, 1, 0, 0, 0, -1,   0], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, -1, 0, 1, 1, 0, 0, -1, -2,   0]]
	c = [s.count(x) for x in ["E", "G", "H", "I", "S", "T", "U", "V", "X", "Z"]]
	a = [sum([a*b for a,b in zip(r,c)]) for r in m]
	s = ""
	for i in range(10):
		s += str(i) * a[i]
	return s

f = open('A-large.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	s = f.readline()
	output = 'Case #{0}: '.format(case) + solve(s) + "\n"
	print(output)
	out.write(output)

out.close()