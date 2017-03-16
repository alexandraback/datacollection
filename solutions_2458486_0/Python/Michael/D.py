import collections

def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

def solve( unopened ):
    if not unopened:
        return ()
    if unopened in cache:
        return None
    for index in range( len( unopened ) ):
        chest = chests[ unopened[ index ] ]
        if keys[ chest[ 0 ] ]:
            keys[ chest[ 0 ] ] -= 1
            for key in chest[ 2 : ]:
                keys[ key ] += 1
            solution = solve( unopened[ : index ] + unopened[ index + 1 : ] )
            if solution is not None:
                return ( unopened[ index ], ) + solution
            keys[ chest[ 0 ] ] += 1
            for key in chest[ 2 : ]:
                keys[ key ] -= 1
    cache.add( unopened )

T = read_integer()
for t in range( T ):
    K, N = read_integers()
    keys = collections.defaultdict( int )
    for key in read_integers():
        keys[ key ] += 1
    chests = [ read_integers() for n in range( N ) ]
    cache = set()
    sequence = solve( tuple( range( N ) ) )
    print 'Case #%i:' % ( t + 1 ), ' '.join( str( index + 1 ) for index in sequence ) if sequence else 'IMPOSSIBLE'
