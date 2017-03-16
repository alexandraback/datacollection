def LCS(B,T):
	if B==[] or T == []:
		return 0
	else:
		if B[1] == T[1]:
			if B[0]<T[0]:
				return B[0] + LCS(B[2:], [T[0]-B[0]]+T[1:])
			if B[0]>T[0]:
				return T[0] + LCS([B[0]-T[0]]+B[1:], T[2:])
			return B[0] + LCS(B[2:],T[2:])
		else:
			return max(LCS(B[2:],T), LCS(B,T[2:]))

T = int(raw_input())

for t in xrange(1,T+1):
	raw_input()
	Boxes = map(int,raw_input().split())
	Toys = map(int,raw_input().split())
	print 'Case #' + str(t) + ': ' + str(LCS(Boxes,Toys))
	
