infile = open('B-large.in', 'r')
outfile = open('test.out', 'w')

T = int(infile.readline())

for t in range(T):
	N = int(infile.readline())
	lists = []
	for _ in range(2*N-1):
		lists.extend(map(int, infile.readline().strip().split(' ')))
	single = []
	for n in lists:
		if n in single:
			single.remove(n)
		else:
			single.append(n)
	single.sort()
	outfile.write('Case #' + str(t+1) + ': ' + ' '.join(map(str, single)) + '\n')