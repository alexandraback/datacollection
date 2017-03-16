T = int(raw_input())


def add_digit(N):
	while (N > 0):
		if (N%10 not in S):
			S.add(N%10)
		N = N/10

#add_digit(111)
#print S

for case in range(1, T+1):
	S = set()
	N = int(raw_input())
	X = N
	step = 1
	if (N == 0):
		print "Case #{}: {}".format(case, 'INSOMNIA')
	else:
		while (len(S) < 10):
			X = step*N
			#print X
			add_digit(X)
			step += 1
		print "Case #{}: {}".format(case, X)
