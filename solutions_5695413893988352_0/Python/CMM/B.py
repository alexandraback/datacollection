def score(CP):
	c = int(CP[0])
	p = int(CP[1])
	
	dif = abs(c-p)
	
	return (dif, c, p)

def solve(C, P):

	if "?" in C:
		low = None
		best = None
		for i in range(10):
			Cc = C.replace("?", str(i), 1)
			x = solve(Cc, P)
			if low is None or score(x) < low:
				low = score(x)
				best = x

		return best

	if "?" in P:
		low = None
		best = None
		for i in range(10):
			Pp = P.replace("?", str(i), 1)
			x = solve(C, Pp)
			if low is None or score(x) < low:
				low = score(x)
				best = x
				
		return best
		
	return (C,P)


CASES = int(raw_input())

case = 1
for i in range(CASES):
	C,P = raw_input().split()
	print ("Case #%d:" % case), " ".join(solve(C,P))
	case += 1
