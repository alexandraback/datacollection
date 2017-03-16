import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())

for case_no in xrange(1, T + 1):
	case = map(float, f.readline()[:-1].split(' '))
	N = case[0]
	S = case[1:]
	ans = []
	X = sum(S)
	E = 2*X/N
	N = 0.0
	X += X
	for s in S:
		if s <= E:
			N += 1
		else:
			X -= s
				
	for s in S:
		if s <= E:
			if X == 0:
				y = (100/N)
			else:
				y = ((1/N-s/X)*200.0)
		else:
			y = 0.0
		ans.append(y)
	X = sum(ans)
	
	for i,s in enumerate(ans):
		ans[i] = "%0.6f" % (s/X * 100.0)
	print("Case #%d: %s" % (case_no, ' '.join(ans)))
