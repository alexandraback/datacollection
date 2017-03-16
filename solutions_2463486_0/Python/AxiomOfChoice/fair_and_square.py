nums = []

def check( s ):
	s = str( int( s ) ** 2 )
	for i in xrange( len( s ) ):
		if s[i] != s[-i-1]:
			return
	nums.append( int( s ) )

for i in xrange( 1, 10 ):
	check( str( i ) )

for l in xrange( 1, 1000 ):
	l = str( l )
	r = l[::-1]
	check( l + r )
	for i in xrange( 10 ):
		check( l + str( i ) + r )

T = int( raw_input() )
for t in xrange( 1, T + 1 ):
	a, b = map( int, raw_input().split() )
	ans = sum( a <= i <= b for i in nums )
	print "Case #{0}: {1}".format( t, ans )
