def solve( r1 , r2 ) :
    att = 0
    st = 0
    f = [ 0 for x in range( len( r1 ) ) ]
    while( True ) :
        a2 = [ x for x in range( len( r2 ) ) if ( ( r2[ x ] <= st ) and ( f[ x ] < 2 ) ) ]
        if ( len( a2 ) > 0 ) :
            st += 2 - f[ a2[ 0 ] ]
            f[ a2[ 0 ] ] = 2
            att += 1
            continue
        a1 = sorted( [ ( r2[ x ] , x ) for x in range( len( r2 ) ) if ( ( r1[ x ] <= st ) and ( f[ x ] < 1 ) ) ] )
        if ( len( a1 ) > 0 ) :
            st += 1
            f[ a1[ len( a1 ) - 1 ][ 1 ] ] = 1
            att += 1
            continue
        break
    if ( sum( f ) == 2 * len( r1 ) ) :
        return att
    else :
        return 'Too Bad'


def main():
    fIn = open( r'C:\gjam\rush\in.txt' )
    fOut = open( r'C:\gjam\rush\out.txt' , 'w' )
    T = int( fIn.readline() )
    for task in range( 1 , T + 1 ) :
        N = int( fIn.readline() )
        r1 = []
        r2 = []
        for n in range( N ) :
            x1 , x2 = [ int( x ) for x in fIn.readline().split() ]
            r1.append( x1 )
            r2.append( x2 )
        fOut.write( 'Case #' + str( task ) + ': ' + str( solve( r1 , r2 ) ) + '\n' )

if __name__ == '__main__':
    main()
