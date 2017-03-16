import sys
N  = int(sys.stdin.readline().strip())
for qw in range(1,N+1):
	tmp = sys.stdin.readline().strip().split()
	K = int(tmp[0])
	C = int(tmp[1])
	S = int(tmp[2])
	print("Case #%d: %s"%(qw," ".join(str(num) for num in range(1,K+1))))