def solve(n):
	if n == 0:
		return "INSOMNIA"
	
	digs = set()
	i = 0
	while len(digs) < 10:
		i += 1
		digs.update([int(c) for c in str(i*n)])
	
	return i*n

f = open('A-large.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	n = int(f.readline().strip())
	output = 'Case #{0}: {1}'.format(case, solve(n)) + "\n"
	print(output)
	out.write(output)

out.close()