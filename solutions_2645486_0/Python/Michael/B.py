def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

def value( e, i ):
    if ( e, i ) in cache:
        return cache[ ( e, i ) ]
    if i == N:
        return e*v[ i ]
    optimum = 0
    for expenditure in range( e + 1 ):
        optimum = max( optimum, expenditure*v[ i ] + value( min( E, e - expenditure + R ), i + 1 ) )
    cache[ ( e, i ) ] = optimum
    return optimum
        
T = read_integer()
for t in range( T ):
    E, R, N = read_integers()
    N -= 1
    v = read_integers()
    cache = {}
    print 'Case #%i:' % ( t + 1 ), value( E, 0 )
