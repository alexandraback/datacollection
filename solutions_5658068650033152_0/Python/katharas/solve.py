
def solve(N, M, K):
	if N>M:
		return solve(M,N,K)
	if K==1:
		return 1
	if K==2:
		return 2
	if K==3:
		return 3
	if K==4:
		return 4
	if K==5:
		if N>=3:
			return 5
		else:
			return 5
	if K==6:
		if N>=3:
			return 6
		else:
			return 6
	if K==7:
		if N>=3:
			return 6
		else:
			return 7
	if K==8:
		if N>=3:
			return 6
		else:
			return 8
	if K==9:
		if N>=3:
			return 7
		else:
			return 9
	if K==10:
		if N>=3:
			return 8
		else:
			return 10
	if K==11:
		if N>=3:
			return 8
		else:
			return 11
	if K==12:
		if N>=4:
			return 8
		else:
			return 9
	if K==13:
		if N>=4:
			return 9
		else:
			return 10
	if K==14:
		if N>=4:
			return 10
		else:
			return 11
	if K==15:
		if N>=4:
			return 11
		else:
			return 12
	if K==16:
		return 10
	return 10 + K-16

T = int(raw_input())
for t in xrange(1,T+1):
	N,M,K = map(int, raw_input().split())
	print "Case #{}: {}".format(t, solve(N,M,K))
