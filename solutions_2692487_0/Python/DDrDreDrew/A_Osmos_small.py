


if __name__ == "__main__":
	fin = open('A-small-attempt2.in', 'r').readlines()
	fout = open('A-small.out', 'wb')
	T = int(fin[0].strip())
	
	for i in xrange(1,2*T+1,2):
		op = 0
		ops = set()
		(A,N) = (int(x.strip()) for x in fin[i].split(' '))
		motes = sorted([int(x.strip()) for x in fin[i+1].split(' ')])
		A2 = A
		m = 0
		while m < len(motes):
			if A > motes[m]: 
				A += motes[m]
				m+=1
			else:
				ops.add(op+N-m)
				if A == 1:
					op += N-m
					m += N-m
				else:
					ad = 0
					while A <= motes[m]:
						A += A-1
						ad += 1
						
					if ad < N-m:
						op += ad
						A += motes[m]
						m += 1
					else:
						op += N-m
						m += N-m
		
		ops.add(op)
		fout.write('Case #{}: {}\n'.format((i+1)/2,min(ops)))










