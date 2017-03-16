import collections
import heapq

def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

T = read_integer()
for t in range( T ):
    wall = collections.defaultdict( int )
    N = read_integer()
    tribes = [ read_integers() for n in range( N ) ]
    heapq.heapify( tribes )
    successes = 0
    build = []
    build_day = 1000000
    while tribes:
        tribe = heapq.heappop( tribes )
        di, ni, wi, ei, si, delta_di, delta_pi, delta_si = tribe
        if build and build_day < di:
            for span in build:
                for section in range( span[ 0 ], span[ 1 ] ):
                    if wall[ section ] < span[ 2 ]:
                        wall[ section ] = span[ 2 ]
            build = []
            #print wall
        success = False
        #print di, ni, wi, ei, si
        for p in range( wi, ei ):
            if wall[ p ] < si:
                success = True
        if success:
            #print 'S'
            successes += 1
            build.append( ( wi, ei, si ) )
            build_day = di
        di += delta_di
        ni -= 1
        wi += delta_pi
        ei += delta_pi
        si += delta_si
        tribe[ : 5 ] = di, ni, wi, ei, si
        if ni:
            tribe = heapq.heappush( tribes, tribe )
    print 'Case #%i:' % ( t + 1 ), successes
