import math

def f(x,C,x0 = None):
	if x0 is None:
		x0 = x

	while C > 1:
		ret = ""
		for c in x:
			if c == "G":
				ret += "G" * len(x0)
			else:
				ret += x0
		x = ret
		C -= 1

	return x

def solve(K,C,S):
	def w(level):
		return K**(C-level)

	def choose_next(x, left, level):
		if len(left) == 0 or level > C:
			return (x,left)
		else:
			(next,rem) = (left[0],left[1:])
			xp = x + next * w(level)
			return choose_next(xp, rem, level+1)

	left = range(K)
	pts = []
	while len(left) > 0:
		#print left
		(x,left) = choose_next(0, left, level = 1)
		pts.append(x)
		if len(pts) > S:
			return "IMPOSSIBLE"

	#print (K,C,S)
	#print pts
	#if K**C < 2000000:
	#	assert check_solution(K,C,S,pts)
	#else:
	#	print "ok" if len(pts) == long(math.ceil(K * 1.0 / C)) else "maybe"
	return " ".join([str(x+1) for x in pts])

def dump(K,C):
	for k in xrange(K):
		x0 = "".join("G" if i == k else "L" for i in range(K))
		print "%s: %s" % (x0, f(x0,C,x0))

def check_solution(K,C,S,pts):
	sets = []
	for k in xrange(K):
		x0 = "".join("G" if i == k else "L" for i in range(K))
		ret = f(x0,C,x0)
		sets.append(set(i for i in xrange(len(ret)) if ret[i] == "G"))
		#print "%s: %s" % (x0, ret)
	
	tmp = set()
	for x in pts:
		tmp |= set(k for k in range(K) if x in sets[k])

	#print sets
	#print tmp
	return len(tmp) == K

if __name__ == '__main__':
	T = int(raw_input())
	for t in range(T):
		(K,C,S) = map(int, raw_input().split())
		print "case #%d: %s" % (t+1, solve(K,C,S))
		#print "---"
		#dump(K,C)
		#print "---"
