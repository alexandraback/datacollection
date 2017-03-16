cases = int(raw_input())


for case in range(1, cases+1):
	C, F, X = map(float, raw_input().split())
	if X < C:
		result = X / 2
	else:
		result = 0
		production = 2.0
		while (X / production) > (C / production +  X / (production + F)):
			result += C / production
			production += F
		result += X / production
	print "Case #%d: %.7f" % (case, result) 
	
	 
	
	
