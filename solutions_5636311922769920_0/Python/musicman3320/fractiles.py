fin = open('D-small-attempt0.in', 'r')
fout = open('D-small-attempt0.out','w')

def PositionForSpots(K,C,S,ks):
	# print ks
	while len(ks) < C:
		ks.append(0)
	for i in range(len(ks)):
		if ks[i] >= K:
			ks[i] = 0
	# print ks
	return sum([ks[c]*(K**c) for c in range(C)])



numlines = int(fin.readline().rstrip())

for line in range(numlines):
	vals = str(fin.readline().rstrip())
	(K,C,S) = tuple([int(c) for c in vals.split(" ")])
	
	result = ""
	
	if C*S < K:
		result = "IMPOSSIBLE"
	else:
		results = []
		for s in range(S):
			pos = PositionForSpots(K,C,S,range(C*s,C*(s+1)))
			results.append(str(pos+1))
			
			if C*(s+1) >= K:
				break
		
		result = " ".join(results)
	
	outstr = "Case #" + str(line+1) + ": " + str(result) + "\n"
	# print outstr.rstrip()
	fout.write(outstr)

