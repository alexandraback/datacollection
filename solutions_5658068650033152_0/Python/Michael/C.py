import heapq
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
for t in range( T ):
    print 'Case #%i:' % ( t + 1 ),
    N, M, K = read_integers()
    x0 = ( M - 1 )/2.0
    y0 = ( N - 1 )/2.0
    p = [ ( ( m - x0 )**2 + ( n - y0 )**2, m, n ) for m in range( M ) for n in range( N ) ]
    p.sort()
    s = set( ( pp[ 1 ], pp[ 2 ] ) for pp in p[ : K ] )
    t = set()
    for m,n in s:
        if m == 0 or m == M - 1 or n == 0 or n == N - 1 or ( m-1, n ) not in s or ( m+1, n ) not in s or ( m, n-1 ) not in s or ( m, n+1 ) not in s:               
            t.add( (m,n) )
    print len( t )
            
