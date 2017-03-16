from fractions import gcd

T = int( input() )
for Ti in range( 1, T+1 ):
    P, Q = [ int(v) for v in input().split( '/' ) ]
    d = gcd( P, Q )
    P, Q = P//d, Q//d
    
    g = 0
    while P >= 2:
        P = P // 2
        if Q%2 == 1:
            g = -1
            break
        Q = Q // 2

    while Q > 1 and g >= 0:
        if Q%2 == 1:
            g = -1
            break

        g += 1
        Q = Q//2

    print( "Case #{0}: {1}".format( Ti, g if g >= 0 else "impossible" ) )

