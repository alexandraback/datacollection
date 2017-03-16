import fractions
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

def read_string_stack():
    data = []
    for line in sys.stdin.readlines():
        data.extend( line.split() )
    data.reverse()
    return data

def read_integer_stack():
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
FACTOR = 2**40
for t in range( T ):
    print 'Case #%i:' % ( t + 1 ),
    P, Q = [ int( x ) for x in read_string().split( '/' ) ]
    gcd = fractions.gcd( P, Q )
    if gcd:
        P //= gcd
        Q //= gcd
    for g in range( 41 ):
        if P >= Q and P*FACTOR % Q == 0:
            print g
            break
        P *= 2
    else:
        print 'impossible'
