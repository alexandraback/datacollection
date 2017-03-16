import sys

def expand( c, data ):
	if ( c[1] == True ):
		return False
	
	origParents = [] 
	origParents.extend( c[0] )
	for parent in origParents:
		parent -= 1
		oldLength = len( c[0] )
		parentData = data[parent]
		if( expand( parentData, data ) ):
			return True
		newParents = data[parent][0]
		newLength = len( newParents )
		c[0].update( newParents )
		if ( len( c[0] ) < oldLength + newLength ):
			return True

	c[1] = True
	return False

numCases = input()
for case in range( 1, numCases + 1 ):
	numClasses = input()

	data = []
	for i in xrange( 1, numClasses + 1 ):
		q = raw_input().split()
		count = int(q[0])
		x = set()
		if ( count > 0 ):
			q = q[1:]
			q = [ int(z) for z in q ]
			x.update( q )
		data.append( [ x, False, i ] )

	diamond = False
	for parent in data:
		if ( expand( parent, data ) ):
			diamond = True
			break
		
	if diamond:
		print 'Case #' + str( case ) + ': Yes'
	else:
		print 'Case #' + str( case ) + ': No'
