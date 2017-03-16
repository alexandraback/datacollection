def solve(cakes):
	cur = cakes[0]
	if cur == "+":
		ans = 0
	else:
		ans = 1
	for c in cakes:
		if c == cur:
			continue
		if c == "-":
			ans += 2
		cur = c
	return ans

t = int(raw_input())
for case in range(1, t + 1):
	cakes = raw_input()
	print "Case #%i: %i" %(case, solve(cakes))
	
      
        
