import math
import operator
import re
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

alphabet = 'abcdefghijklmnopqrstuvwxyz'

def start( train ):
    for s in train:
        if not any( s != t and s[ 0 ] == t[ 1 ] for t in train ):
            return s

def valid( cars ):
    for i in range( len( cars ) ):
        for c in alphabet:
            cars[ i ] = re.sub( c + '+', c, cars[ i ] )
    for i, car in enumerate( cars ):
        for letter in car[ 1 : -1 ]:
            if any( letter in test for test in cars[ : i ] + cars[ i + 1 : ] ):
                return 0
    for i in range( len( cars ) ):
        cars[ i ] = cars[ i ][ 0 ] + cars[ i ][ -1 ]
    for c in alphabet:
        if sum( car[ 0 ] == c and car[ 1 ] != c for car in cars ) > 1 or sum( car[ 1 ] == c and car[ 0 ] != c for car in cars ) > 1:
            return 0
    cars.sort()
    train = []
    for w in cars:
        if train and w == train[ -1 ][ 0 ]:
            train[ -1 ][ 1 ] += 1
        else:
            train.append( [ w, 1 ] )
    train = dict( train )
    short = []
    while train:
        s = start( train )
        if not s:
            return 0
        short.append( [ s, train[ s ] ] )
        del train[ s ]
        while train:
            for n in train.copy():
                if n[ 0 ] == short[ -1 ][ 0 ][ -1 ]:
                    short[ -1 ][ 0 ] += n
                    short[ -1 ][ 1 ] *= train[ n ]
                    del train[ n ]
                    break
            else:
                break
    total = 1
    for s in short:
        total = total*s[ 1 ] % 1000000007
    return total*( math.factorial( len( short ) ) % 1000000007 ) % 1000000007

T = read_integer()
for t in range( T ):
    print 'Case #%i:' % ( t + 1 ),
    N = read_integer()
    cars = read_strings()
    print valid( cars )            
