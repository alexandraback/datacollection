'''Qualification Round Problem D. Hall of Mirrors'''

import sys

def log( msg ):
    print( msg )
    print( msg, file = sys.stderr )


def small( w, h, posX, posY, d ):
    def isIn( x1, y1, x2, y2, distance ):
        xd = x1 - x2
        yd = y1 - y2
        return ( xd * xd + yd * yd ) <= ( distance * distance )

    def isInLine( posX, posY, x1, y1, x2, y2 ):
        return posX * ( y1 - y2 ) + x1 * ( y2 - posY ) + x2 * ( posY - y1 ) == 0

    mirroredSet = [
        ( posX, posY ),
        ( 2 * w - 1 - posX, posY ),
        ( posX, 2 * h - 1 - posY ),
        ( 2 * w - 1 - posX, 2 * h - 1 - posY ) ]

    # gather points where distance from pos is less than d
    results = {}
    for i in range( -25, 26 ):
        for j in range( -25, 26 ):
            for mirroredX, mirroredY in mirroredSet:
                copiedX = w * 2 * i + mirroredX
                copiedY = h * 2 * j + mirroredY

                if copiedX == posX and copiedY == posY:
                    pass
                elif not isIn( copiedX, copiedY, posX, posY, d ):
                    pass
                else:
                    results[ ( copiedX, copiedY ) ] = True

    # remove points on the same line
    for x1, y1 in results.keys():
        if not results[ ( x1, y1 ) ]:
            continue

        for x2, y2 in results.keys():
            if x1 == x2 and y1 == y2:
                continue
            elif not results[ ( x2, y2 ) ]:
                continue

            if not isInLine( posX, posY, x1, y1, x2, y2 ):
                pass
            elif ( posX - x1 ) * ( posX - x2 ) <= 0 and ( posY - y1 ) * ( posY - y2 ) <= 0:
                pass
            else:
                results[ x2, y2 ] = False

    # count unique positions
    count = 0
    for result in results.values():
        if result:
            count += 1

    return count


def large():
    return 0


def main( input ):
    count = int( input.readline() )

    for index in range( 1, count + 1 ):
        line = input.readline().replace( '\n', '' )
        h, w, d = tuple( map( int, line.split( ' ' ) ) )

        for i in range( h ):
            line = input.readline()
            j = line.find( 'X' )
            if j > 0:
                posX, posY = j - 1, i - 1

        result = small( w - 2, h - 2, posX, posY, d )

        log( 'Case #{}: {}'.format( index, result ) )


main( sys.stdin )
#main( open( 'D:/Works/codejam/2012/input.txt' ) )
