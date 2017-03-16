'''Qualification Round Problem B. Dancing With the Googlers'''

import sys


def calc( points, p, surprising ):
    count = 0

    for point in points:
        mod = point % 3
        base = point // 3

        if mod == 0:
            if base >= p:
                count += 1
            elif base + 1 == p and base != 0 and surprising > 0:
                surprising -= 1
                count += 1

        elif mod == 1:
            if base + 1 >= p:
                count += 1

        elif mod == 2:
            if base + 1 >= p:
                count += 1
            elif base + 2 == p and surprising > 0:
                surprising -= 1
                count += 1

    return count


def main( input ):
    count = int( input.readline() )

    for index in range( 1, count + 1 ):
        source = input.readline().replace( '\n', '' )
        numbers = tuple( map( int, source.split( ' ' ) ) )

        n = numbers[ 0 ]
        surprising = numbers[ 1 ]
        p = numbers[ 2 ]
        points = numbers[ 3 : ]
        assert n == len( points )

        result = calc( points, p, surprising )

        print( 'Case #{}: {}'.format( index, result ) )


main( sys.stdin )
