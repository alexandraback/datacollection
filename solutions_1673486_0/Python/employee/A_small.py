import sys


t = int( sys.stdin.readline() )
for case in range( t ):
    a, b = map( int, sys.stdin.readline().split() )
    e = min( b + 2, a + b + 1 )
    p = 1
    r = a + b + 1
    for p_ in map( float, sys.stdin.readline().split() ):
        p *= p_
        r -= 2
        w = r + ( b + 1 )
        e = min( e, p * r + ( 1 - p ) * w )
    print( 'Case #{}: {}'.format( case + 1, e ) )
