def solve(c, f, x):
	v = 2
	t = c/v
	while v*c < f*(x - c):
		v += f
		t += c/v
	t += (x - c)/v
	return t

fin, fout = open('b.in'), open('b.out', 'w')
answer = 'Case #{0}: {1:.7f}'
t = int(fin.readline())
for i in range(t):
	c, f, x = map(float, fin.readline().split())
	print(answer.format(i + 1, solve(c, f, x)), file=fout)
fin.close()
fout.close()
