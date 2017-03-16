import sys

cases = sys.stdin.readline()


for case in range(0,int(cases)):	
	A,N = [int(v) for v in sys.stdin.readline().split()]
	moles = [int(v) for v in sys.stdin.readline().split()]
	moles = sorted(moles)

	res_min = N
	res_tmp = 0

	res_tmps = []
	for mole in moles:
		if A == 1:
			res_tmp += 1
		else:
			while mole >= A: 
				res_tmp += 1
				A += A - 1
			A += mole
		res_tmps.append(res_tmp)

	for i in range(0, N):
		res_min = min(res_min, res_tmps[i] + N - i - 1)
			
	print "Case #%d: %d" % (case+1, res_min)
