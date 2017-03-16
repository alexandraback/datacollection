import sys
from math import floor
for i in xrange( int( raw_input( ) ) ):
    N = int( raw_input( ) )
    R = range( N )
    dP = [ list( set( map( int, raw_input( ).split( ' ' )[ 1 : ] ) ) ) for j in R ]
    for j in R:
        for k in xrange( len( dP[ j ] ) ):
            dP[ j ][ k ] -= 1
    dC = [ [ k for k in R if j in dP[ k ] ] for j in R ]
    
    E = [ j for j in R if len( dC[ j ] ) > 1 ]
    S = [ j for j in R if len( dP[ j ] ) > 1 ]
    
    if len( S ) < 1 or len( E ) < 1:
        result = False
    else:
        def numberOfPathToBetween( s, e ):
            if s == e:
                return 1
            else:
                return sum( [ numberOfPathToBetween( n, e ) for n in dP[ s ] ] )
        
        def getResult( ):
            for s in S:
                for e in E:
                    if numberOfPathToBetween( s, e ) > 1:
                        return True
            return False
        
        result = getResult( )
        
    
    if result:
        result = 'Yes'
    else:
        result = 'No'
    print( 'Case #' + str( i + 1 ) + ': ' + result )