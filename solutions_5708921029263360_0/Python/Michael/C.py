import collections
import sys

def read_line():
    return sys.stdin.readline().rstrip( '\n' )

def read_integer( base = 10 ):
    return int( read_line(), base )

def read_integers( base = 10 ):
    return [ int( x, base ) for x in read_line().split() ]

def read_float():
    return float( read_line() )

def read_floats():
    return [ float( x ) for x in read_line().split() ]

def read_string():
    return read_line().strip()

def read_strings():
    return read_line().split()

def input_string_stack():
    data = []
    for line in sys.stdin.readlines():
        data.extend( line.split() )
    data.reverse()
    return data

def input_integer_stack():
    return [ int( x ) for x in read_string_stack() ]

def bits( x ):
    return bin( x ).count( '1' )

class memoized( object ):
   def __init__( self, function ):
      self.function = function
      self.cache = {}
   def __call__( self, *arguments ):
      try:
         return self.cache[ arguments ]
      except KeyError:
         value = self.function( *arguments )
         self.cache[ arguments ] = value
         return value

T = read_integer()
for t in range( T ):
    print 'Case #%i:' % ( t + 1 ),
    J, P, S, K = read_integers()
    JP_combinations = collections.defaultdict( int )
    JS_combinations = collections.defaultdict( int )
    PS_combinations = collections.defaultdict( int )
    outfits = []
##    print
    for j in range( J ):
        for p in range( P ):
##            if JP_combinations[ ( j, p ) ] == K:
##                continue
            for s in range( S ):
                if JP_combinations[ ( j, p ) ] == K or JS_combinations[ ( j, s ) ] == K or PS_combinations[ ( p, s ) ] == K:
                     continue
                JP_combinations[ ( j, p ) ] += 1
                JS_combinations[ ( j, s ) ] += 1
                PS_combinations[ ( p, s ) ] += 1
                outfits.append( ( j, p, s ) )
##                print outfits[-1]
##                print '\t', sorted( JP_combinations.items() )
##                print '\t', sorted( JS_combinations.items() )
##                print '\t', sorted( PS_combinations.items() )
    print len( outfits )
#    assert len( outfits ) == min( K, J )*min( K, P )*min( K, S )
    for outfit in outfits:
        print ' '.join( str( item + 1 ) for item in outfit )
