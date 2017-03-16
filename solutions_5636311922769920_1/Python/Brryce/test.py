import sys
N  = int(sys.stdin.readline().strip())
for qw in range(1,N+1):
	tmp = sys.stdin.readline().strip().split()
	K = int(tmp[0])
	C = int(tmp[1])
	S = int(tmp[2])
	length = K**C
	mark = K//C
	if K%C >0:
		mark = (K//C)+1
	if S<mark:
		print("Case #%d: IMPOSSIBLE"%qw)
		continue
	result = []
	base = 1
	for ite in range(1,C):
		base +=ite*K**ite
	distance = C
	for ite in range(1,C):
		distance +=C*K**ite
	for ite in range(mark):
		decide = base+distance*ite
		if base >length:
			result.append(K)
		elif decide > length:
			result.append(length)
		else:
			result.append(decide)
	print("Case #%d: %s"%(qw," ".join(str(num) for num in result)))


