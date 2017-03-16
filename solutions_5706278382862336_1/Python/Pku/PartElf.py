import fractions

T = int(raw_input())

results = []

for k in xrange(T):
	numer, denom = map(int, raw_input().split("/"))
	g = fractions.gcd(numer, denom)
	numer = numer / g
	denom = denom / g
	result = 0
	#print "numer, denom:", numer, denom
	bindenom = bin(denom)[2:]
	for i in xrange(1,len(bindenom)):
		if bindenom[i] == "1":
			result = -1
	if result == -1:
		results.append(result)
	else: 
		frac = float(numer)/float(denom)
		result = 0
		for i in xrange(1,40):
			piece = 2**(-1*i)
			if piece <= frac:
				frac -= piece
				if result == 0:
					result = i
		if frac != 0:
			result = -1
		results.append(result)

"""
for k in xrange(T):
	if results[k] == -1:
		print "Case #{}: impossible".format(k+1)
	else:
		print "Case #{}: {}".format(k+1, results[k])

"""
f = open("PartElfOut.txt", 'w')
for k in xrange(T):
	if results[k] == -1:
		print >> f, "Case #{}: impossible".format(k+1)
	else:
		print >> f, "Case #{}: {}".format(k+1, results[k])
f.close()

