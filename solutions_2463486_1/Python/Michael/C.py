from math import *

def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

def build( number, length, position ):
    global count
    for digit in '0123456789':
        if position == 0 and digit == '0':
            continue
        number[ position ] = digit
        if position + 1 == ( length + 1 )//2:
            left = ''.join( number )
            value = int( left + left[ -( length % 2 + 1 ) : : -1 ] )
            if A_root <= value <= B_root:
                word2 = str( value*value )
                if word2 == word2[ : : -1 ]:
                    count += 1
        else:
            build( number, length, position + 1 )

T = read_integer()
for t in range( T ):
    A, B = read_integers()
    A_root = int( ceil( sqrt( A ) ) )
    B_root = int( floor( sqrt( B ) ) )
    A_length = len( str( A_root ) )
    B_length = len( str( B_root ) )
    count = 0
    for length in range( A_length, B_length + 1 ):
        number = [ None for index in range( ( length + 1 )//2 ) ]
        build( number, length, 0 )
    print 'Case #%i:' % ( t + 1 ), count
