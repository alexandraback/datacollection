from math import factorial

letters = "abcdefghijklmnopqrstuvwxyz"
empty = set()
def print_m(m):
    for l in letters:
        if len( m[l][0] ) > 0 or len( m[l][1] ) > 0 or len( m[l][2] ) > 0:
            print( l, m[l] )

T = int( input() )
for Ti in range( 1, T+1 ):

    N = int( input() )
    cars = set( [ ( v[0], v[1:-1], v[-1], i, 1 ) for i, v in enumerate( input().split() ) ] )
    m = {}
    for l in letters:
        m[l] = [ set(), set(), set() ]
    for car in cars:
        m[car[0]][0].add( car )
        for l in letters:
            if l in car[1]:
                m[l][1].add( car )
        m[car[2]][2].add( car )

    count = 0
    for l in letters:
        for mid in m[l][1]:
            if mid[0] != l and m[l][2] != set( ( mid, ) ):
                count = -1
                break

            if mid[2] != l and m[l][0] != set( ( mid, ) ):
                count = -1
                break

        if count == -1: break

    if count == -1:
        print( "Case #{0}: 0".format( Ti ) )
        continue

    stop = False
    while not stop:
        stop = True
        for l in letters:
            left = None
            right = None
            if len( m[l][0] ) == 1 and len( m[l][2] - m[l][0] ) == 1:
                left = ( m[l][2] - m[l][0] ).pop()
                right = m[l][0].pop()
                m[l][2] = set()

            if len( m[l][2] ) == 1 and len( m[l][0] - m[l][2] ) == 1:
                left = m[l][2].pop()
                right = ( m[l][0] - m[l][2] ).pop()
                m[l][0] = set()

            if left == None or right == None:
                continue

            cars.discard( left )
            m[left[0]][0].discard( left )
            for ch in left[1]:
                m[ch][1].discard( left )

            cars.discard( right )
            m[right[2]][2].discard( right )
            for ch in right[1]:
                m[ch][1].discard( right )

            new = ( left[0], left[1] + left[2] + right[0] + right[1], right[2], left[3], 1 )
            cars.add( new )
            m[new[0]][0].add( new )
            m[new[2]][2].add( new )
            for ch in new[1]:
                m[ch][1].add( new )
            stop = False

    if len( cars ) == 1:
        print( "Case #{0}: 1".format( Ti ) )
        continue

    stop = False
    while not stop:
        stop = True
        for l in letters:
            r = []
            for c in m[l][0]:
                if c[0] == l and c[2] == l:
                    r.append( c )
            if len(r) <= 1:
                continue

            for ri in r:
                cars.discard( ri )
                m[l][0].discard( ri )
                m[l][2].discard( ri )
                for ch in ri[1]:
                    m[ch][1].discard( ri )
            m[ch][1].discard( left )

            new = ( l, '', l, r[0][3], factorial( len(r) ) )
            cars.add( new )
            m[new[0]][0].add( new )
            m[new[2]][2].add( new )
            for ch in new[1]:
                m[ch][1].add( new )

    r = factorial( len( cars ) )
    for car in cars:
        r *= car[4]
    print( "Case #{0}: {1}".format( Ti, r ) )
