import sys

T = int(sys.stdin.readline().strip())

def block(t,K,C,S):
	if S<(K-C + 1):
		print "Case #%d: IMPOSSIBLE"%(t+1)
		return
	print "Case #%d:"%(t+1),
	begin = 0
	for layer in range(1,min(K+1,C)):
		begin += (layer-1) * K**(C-layer)

	for x in range(C,K+1):
		print begin+x,
	if C > K:
		print begin+1,
	print ""

for t in range(T):
	K,C,S = [int(x) for x in sys.stdin.readline().strip().split()]
	block(t,K,C,S)


