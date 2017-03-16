t = input()
 
i = 0
while i < t:
    E, R, N = raw_input().split()
    E = int(E)
    R = int(R)
    N = int(N)
    A = raw_input().split()
    for ll in xrange(0, N):
	A[ll] = int(A[ll])
    possibilities = [(E,0)]
    ans = 0
    
    for z in xrange(0, N):
	dt = []
	while len(possibilities) > 0:
	    b = possibilities.pop(0)
	    for y in xrange(min(E,max(0,R-E+b[0])),b[0]+1):
		my_energy = b[0]-y
		my_energy = min(my_energy + R, E)
		ina = b[1] + y * A[z]
		ans = max(ans, ina)
		dt.append((my_energy, ina))
	possibilities = dt
	"""
    ans = 0
    for q in A:
	if q == max(A) or R > E:
	    ans+= E*q
	else:
	    ans+= R*q
	    """
    print "Case #" + `i+1` + ": " + str(ans)
    i=i+1

