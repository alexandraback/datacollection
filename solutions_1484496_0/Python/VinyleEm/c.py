def print_list( v , mask):
	vv = [v[x] for x in xrange(25) if (mask&1<<x) ] ;

	for i in vv:
		print i, ;
	print ;

def solve(v):
	n = len(v) ;

	nset = {} ;

	for mask in xrange(1 , 1<<n):
		sm = 0 ;
		for i in xrange(n) :
			if (mask & 1<<i) :
				sm += v[i] ;

		if sm in nset :
			print_list( v , nset[sm] ) ;
			print_list( v , mask ) ;
			return True ;

		nset[sm] = mask ;
	
	return False ;


cases = int(raw_input() ) ;

for x in xrange(cases):
	l = map(int,raw_input().split()) ;
	v = l[1:] ;

	print "Case #%d:" %(x+1) ; 
	if not solve(v) :
		print "Impossible" ;

