
vect = None

def solve(s, elem):
	global vect
	if s == 1: return len(vect)
	
	#print '<%d, %d>' % (s, elem)  #
	while elem < len(vect) and s > vect[elem]:
		#print '%d mangia %d' % (s, vect[elem]) #
		s += vect[elem]
		elem += 1

	if elem >= len(vect): return 0
	
	# Operazioni da fare
	s0 = s
	# Aggiunta 
	z = 0
	while True:
		s += s -1
		z += 1
		if s > vect[elem]: break
	#print '%d cresce con %d step in %d e mangerebbe %d' % (s0, z, s, vect[elem]) #
	return min( solve(s, elem) +z, solve(s0, elem+1) +1)


def main():
	global vect
	
	tCases = input()
	for i in xrange(tCases):
		dimOsmos, vSize = [int(x) for x in raw_input().split()]
		vect = [int(x) for x in raw_input().split()]
		vect.sort()
	
		#print dimOsmos, vect #
		sol = solve(dimOsmos, 0)
		
		print 'Case #%s: %d' % (i+1, sol)
	

if __name__ == "__main__":
	main()

