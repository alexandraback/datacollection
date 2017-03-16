'''Online Round 1C Problem B. '''

import sys


def solve( x, y ):
    result = ''

    if x > 0:
        result += 'WE' * x
    elif x < 0:
        result += 'EW' * -x

    if y > 0:
        result += 'SN' * y
    elif y < 0:
        result += 'NS' * -y

    return result


def main( input ):
    count = int( input.readline() )
    for index in range( 1, count + 1 ):
        x, y = tuple( map( int, input.readline().replace( '\n', '' ).split() ) )

        result = solve( x, y )
        print( 'Case #{}: {}'.format( index, result ) )
        #print( 'Case #{}: {}'.format( index, result ), file=sys.stderr )


#main( open( 'D:/Works/nt-kookii/sources/python/natuum/GCJ 2013/input.txt' ) )
main( sys.stdin )
