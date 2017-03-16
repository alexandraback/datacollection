import resource
import sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

def f(e, a, b, g):
	if a == b: return 0
	v, i = max((vs[ii],ii) for ii in xrange(a,b))
	available = min((i-a)*R + e, E)
	mustkeep = max(g - (b-i)*R, 0)
	use = available - mustkeep
	#print (e, a, b, g), (v, i), (available, mustkeep, use)
	return f(e, a, i, available) + use*v + f(min(mustkeep+R,E), i+1, b, g)

T = int(sys.stdin.readline())
for t in xrange(T):
	E, R, N = map(int, sys.stdin.readline().split())
	vs = map(int, sys.stdin.readline().split())
	print "Case #%d: %d" % (t+1, f(E, 0, N, 0))
