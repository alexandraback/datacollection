import sys

def solve():
	e,r,n = map(int, sys.stdin.readline().strip().split())
	v = map(int, sys.stdin.readline().strip().split())
	mx = max(v)
	if r>e: r=e
	res = sum([i*r for i in v])
	if (e>r): res += mx * (e-r)
	return res

T = int(raw_input())
for x in xrange(T):
	print "Case #" + str(x+1) + ": " + str(solve())