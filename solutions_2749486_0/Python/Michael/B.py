def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

T = read_integer()
board = [ [ None ]*401 for row in range( 401 ) ]
board[ 200 ][ 200 ] = True
start = [ ( 200, 200 ) ]
for d in range( 1, 101 ):
    next = []
    for x, y in start:
        if x + d <= 400 and not board[ x + d ][ y ]:
            board[ x + d ][ y ] = ( x, y, 'E' )
            next.append( ( x + d, y ) )
        if x - d >= 0 and not board[ x - d ][ y ]:
            board[ x - d ][ y ] = ( x, y, 'W' )
            next.append( ( x - d, y ) )
        if y + d <= 400 and not board[ x ][ y + d ]:
            board[ x ][ y + d ] = ( x, y, 'N' )
            next.append( ( x, y + d ) )
        if y - d >= 0 and not board[ x ][ y - d ]:
            board[ x ][ y - d ] = ( x, y, 'S' )
            next.append( ( x, y - d ) )
    start = next
    if not start:
        break

for t in range( T ):
    X, Y = read_integers()
    X += 200
    Y += 200
    path = []
    while board[ X ][ Y ] is not True:
        path += board[ X ][ Y ][ 2 ]
        X, Y = board[ X ][ Y ][ : 2 ]
    print 'Case #%i:' % ( t + 1 ), ''.join( reversed( path ) )
