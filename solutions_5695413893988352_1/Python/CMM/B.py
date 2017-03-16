def score(CP):
	c = int(CP[0])
	p = int(CP[1])
	
	dif = abs(c-p)
	
	return (dif, c, p)

def solve(C, P):
	if "?" not in C and "?" not in P:
		return (C,P)
	
	cq = C.find("?")
	if cq == -1: cq = 1e11
	pq = P.find("?")
	if pq == -1: pq = 1e11
	i = min(cq,pq)
	#print "---",cq,pq,i
	if C[i] == "?" and P[i] == "?":
		if C[:i] == P[:i]:
			cc = C.replace("?", "0", 1)
			pp = P.replace("?", "0", 1)
			
			s1 = solve(cc, pp)
			
			cc = C.replace("?", "0", 1)
			pp = P.replace("?", "1", 1)
			
			s2 = solve(cc, pp)
			
			if score(s1) < score(s2):
				best = s1
			else:
				best = s2
			
			cc = C.replace("?", "1", 1)
			pp = P.replace("?", "0", 1)
			
			s3 = solve(cc, pp)
			if score(s3) < score(best):
				best = s3
		elif C[:i] > P[:i]:
			return solve(C.replace("?", "0", 1), P.replace("?", "9", 1))
			
		else:
			return solve(C.replace("?", "9", 1), P.replace("?", "0", 1))
		
	elif C[i] == "?":
		
		if C[:i] == P[:i]:
			pi = int(P[i])
			cc = C.replace("?", str(pi), 1)
			s1 = solve(cc, P)
			best = s1
			
			if pi < 9:
				cc = C.replace("?", str(pi+1), 1)
				s2 = solve(cc, P)
				
				if score(s2) < score(best):
					best = s2
			
			if pi > 0:
				cc = C.replace("?", str(pi-1), 1)
				s3 = solve(cc, P)
				
				if score(s3) < score(best):
					best = s3
					
		elif C[:i] > P[:i]:
			return solve(C.replace("?", "0", 1), P)
			
		else:
			return solve(C.replace("?", "9", 1), P)
		
	elif P[i] == "?":
		if C[:i] == P[:i]:
			ci = int(C[i])
			pp = P.replace("?", str(ci), 1)
			s1 = solve(C, pp)
			best = s1
			
			if ci < 9:
				pp = P.replace("?", str(ci+1), 1)
				s2 = solve(C, pp)
				
				if score(s2) < score(best):
					best = s2
			
			if ci > 0:
				pp = P.replace("?", str(ci-1), 1)
				s3 = solve(C, pp)
				
				if score(s3) < score(best):
					best = s3
					
		elif C[:i] > P[:i]:
			return solve(C, P.replace("?", "9", 1))
		else:
			return solve(C, P.replace("?", "0", 1))
			
	else:
		print "???????"
	return best


CASES = int(raw_input())

case = 1
for i in range(CASES):
	C,P = raw_input().split()
	print ("Case #%d:" % case), " ".join(h[1:-1] for h in solve("0"+C+"0","0"+P+"0"))
	case += 1
