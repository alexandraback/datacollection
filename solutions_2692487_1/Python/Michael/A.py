def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

def fork( A, index = 0 ):
    if ( A, index ) in cache:
        return cache[ ( A, index ) ]
    #print ' '*2*index, A, index, count
    while index < len( motes ) and A > motes[ index ]:
        A += motes[ index ]
        #print ' '*2*index, '[%i]' % motes[ index ]
        index += 1
    if index == len( motes ):
        result = 0
    else:
        result = min( fork( A, index + 1 ), fork( 2*A - 1, index ) ) + 1
        cache[ ( A, index ) ] = result
    return result

T = read_integer()
for t in range( T ):
    A, N = read_integers()
    motes = read_integers()
    motes.sort()
    #print motes
    cache = {}
    print 'Case #%i:' % ( t + 1 ), len( motes) if A == 1 else fork( A )
