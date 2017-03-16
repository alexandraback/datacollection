T=int(raw_input())
for case in xrange(T):
	N,M=map(int,raw_input().split())
	A=[map(int,raw_input().split()) for i in xrange(N)]
	line_max=[max(i) for i in A]
	col_max=[max(A[i][j] for i in xrange(N)) for j in xrange(M)]
	R=[[min(line_max[i],col_max[j]) for j in xrange(M)] for i in xrange(N)]
	if A==R:
		ret='YES'
	else:
		ret='NO'
	print 'Case #%d:'%(case+1),ret
