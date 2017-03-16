if __name__ == "__main__":

	fin = open('B-large.in', 'r').readlines()
	fout = open('B-large.out', 'wb')
	T = int(fin[0].strip())
	
	j = 1
	for i in xrange(1,T+1):
		N,M = int(fin[j].split(' ')[0]), int(fin[j].split(' ')[1])
		lawn = [[int(h) for h in fin[k].split(' ')] for k in xrange(j+1,j+1+N)]
		rowmax = [max(lawn[r]) for r in xrange(N)]
		colmax = [max(lawn[r][c] for r in xrange(N)) for c in xrange(M) ]
		lawn2 = [[min(rowmax[r],colmax[c]) for c in xrange(M)] for r in xrange(N)]
		j += N+1

		if lawn == lawn2: 	fout.write('Case #{}: YES\n'.format(i))
		else: 				fout.write('Case #{}: NO\n'.format(i))
	