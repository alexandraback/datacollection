def solve(n):
	if n == 0:
		return "INSOMNIA"
	seen = [False] * 10
	c = 0
	while not all(seen):
		c += n
		cc = c
		while cc:
			seen[cc % 10] = True
			cc /= 10
	return str(c)


t = int(raw_input())
for case in range(1, t + 1):
	n = int(raw_input())
	print "Case #%i: %s" %(case, solve(n))
	
      
        
