'''Online Round 1A Problem A. Speaking in Tongues'''

import sys


def solve( a, b, pList ):
    accList = []
    baseP = 1.0
    for p in pList:
        baseP *= p
        accList.append( baseP )


    def success( index ):
        return accList[ index ]

    def fail( index ):
        return 1.0 - accList[ index ]


    # enter
    if a == b:
        enter = success( a - 1 ) * 1 + fail( a - 1 ) * ( b + 2 )
    else:
        enter = b + 2

    # keep typing

    # backspace
    result = enter
    for i in range( 0, a + 1 ):
        n = i + success( a - i - 1 ) * ( b - a + i + 1 ) + fail( a - i - 1 ) * ( b - a + i + b + 2 )
        if n < result:
            result = n

    return result


def main( input ):
    count = int( input.readline() )
    for index in range( 1, count + 1 ):
        a, b = tuple( map( int, input.readline().replace( '\n', '' ).split( ' ' ) ) )
        pList = tuple( map( float, input.readline().replace( '\n', '' ).split( ' ' ) ) )

        result = solve( a, b, pList )

        print( 'Case #{}: {:0.6f}'.format( index, result ) )


main( sys.stdin )
#main( open( 'D:/Works/codejam/2012/input.txt' ) )
