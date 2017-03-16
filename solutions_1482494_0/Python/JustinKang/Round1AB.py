'''Online Round 1A Problem B. Kingdom Rush'''

import sys


def solve( n, levels ):
    levels.sort( key = lambda entry: entry[ 1 ] * 10000 + entry[ 0 ] )
    cleared = [ False ] * n

    stars = 0
    result = 0
    trying = True

    for c in range( n ):
        r1, r2 = levels[ c ]

        while trying:
            if r2 <= stars:
                stars += ( 1 if cleared[ c ] else 2 )
                result += 1
                cleared[ c ] = True
                break

            else:
                for i in range( n - 1, c - 1, -1 ):
                    o1, o2 = levels[ i ]
                    if not cleared[ i ] and o1 <= stars:
                        stars += 1
                        result += 1
                        cleared[ i ] = True
                        break
                else:
                    trying = False
                    break

        if not trying:
            break


    return result if trying else 'Too Bad'


def main( input ):
    count = int( input.readline() )
    for index in range( 1, count + 1 ):
        n = int( input.readline() )
        levels = []
        for i in range( n ):
            r1, r2 = tuple( map( float, input.readline().replace( '\n', '' ).split( ' ' ) ) )
            levels.append( ( r1, r2 ) )

        result = solve( n, levels )

        print( 'Case #{}: {}'.format( index, result ) )


main( sys.stdin )
#main( open( 'D:/Works/codejam/2012/input.txt' ) )
