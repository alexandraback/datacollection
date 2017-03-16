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
    B, M = read_integers()
#    print
    solved = False
    A = [ B*[ 0 ] for row in range( B ) ]
    for index in range( 1, 2**( B*( B - 1 )/2 ) ):
        bits = index
        for row in range( B - 1 ):
            for column in range( row + 1, B ):
                A[ row ][ column ] = bits & 0x1
                bits >>= 1
        assert not bits
        paths = B*[ 0 ]
        paths[ -1 ] = 1
        for row in range( B - 2, -1, -1 ):
            for column in range( row + 1, B ):
                paths[ row ] += A[ row ][ column ]*paths[ column ]
##        print index, M, paths[ 0 ]
##        for row in range( B ):
##            print ''.join( str( x ) for x in A[ row ] )
        if paths[ 0 ] == M:
            print 'POSSIBLE'
            for row in range( B ):
                print ''.join( str( x ) for x in A[ row ] )
            solved = True
            break
##        else:
##            print 'IMPOSSIBLE'
    if not solved:
        print 'IMPOSSIBLE'
##
##
##01001
##00110
##00011
##00001
##00000
##
##03211
