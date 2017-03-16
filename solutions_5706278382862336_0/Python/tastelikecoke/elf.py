case = 0
cases = int(raw_input())
while case != cases:
	case += 1
	s = raw_input()
	s = s.split("/")
	a = int(s[0])
	b = int(s[1])
	gen = 0
	denom = 1
	num = 2
	while denom < b:
		denom *= 2
		gen += 1	
	while num < a:
		num *= 2
		gen -= 1
	if denom != b:
		print  "Case #"+str(case)+": "+"impossible"
	else:
		print "Case #"+str(case)+": "+str(gen)