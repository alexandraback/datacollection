import sys
import collections


t = int( sys.stdin.readline() )
for case in range( t ):
    n = int( sys.stdin.readline() )
    a = [ None ] * n
    b = [ None ] * n
    a_ = collections.defaultdict( set )
    b_ = collections.defaultdict( set )
    for i in range( n ):
        a[ i ], b[ i ] = map( int, sys.stdin.readline().split() )
        a_[ a[ i ] ].add( i )
        b_[ b[ i ] ].add( i )
        
    s = 0
    r = 0
    ia = sorted( a_ )
    ib = sorted( b_ )
    
    while True:
        r_ = r
        
        for rs in ib:
            if s < rs:
                break
            
            for i_ in b_[ rs ]:
                r += 1
                if a[ i_ ] is not None:
                    a_[ a[ i_ ] ].remove( i_ )
                    a[ i_ ] = None
                    s += 2
                else:
                    s += 1
            del b_[ rs ]
            
        if not b_:
            break
        ib = sorted( b_ )
        rs_ = ib[ 0 ]
            
        for rs in ia:
            if s < rs:
                break
            
            for i_ in tuple( a_[ rs ] ):
                r += 1
                a_[ a[ i_ ] ].remove( i_ )
                a[ i_ ] = None
                s += 1
                if rs_ <= s:
                    break
                
            if not a_[ rs ]:
                del a_[ rs ]
                
            if rs_ <= s:
                break
        ia = sorted( a_ )
        
        if r_ == r:
            r = None
            break
        
    print( 'Case #{}: {}'.format( case + 1, 'Too Bad' if r is None else r ) )
