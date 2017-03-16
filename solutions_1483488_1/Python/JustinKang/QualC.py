'''Qualification Round Problem C. Recycled Numbers'''

import sys

def debug( msg ):
    print( msg, file = sys.stderr )


def small( a, b ):
    def isRecycled( n, m ):
        if n == m:
            return True

        n = str( n )
        m = str( m )

        for i in range( 1, len( n ) ):
            if n[ i : ] + n[ 0 : i ]  == m:
                return True

        return False

    count = 0

    for n in range( a, b ):
        for m in range( n + 1, b + 1 ):
            if isRecycled( n, m ):
                count += 1

    return count


def large( a, b ):
    count = 0

    for n in range( a, b ):
        candidate = str( n )
        duplication = set()

        for i in range( 1, len( candidate ) ):
            m = int( candidate[ i : ] + candidate[ 0 : i ] )
            if m > n and m <= b and m not in duplication:
                duplication.add( m )
                count += 1

    return count


def main( input ):
    count = int( input.readline() )

    for index in range( 1, count + 1 ):
        source = input.readline().replace( '\n', '' )
        a, b = tuple( map( int, source.split( ' ' ) ) )

        result = large( a, b )

        print( 'Case #{}: {}'.format( index, result ) )
        debug( 'Case #{}: {}'.format( index, result ) )


main( sys.stdin )
