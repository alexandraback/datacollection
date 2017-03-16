'''Qualification Round Problem A. Speaking in Tongues'''

import sys


def buildTable( source, target ):
    table = {}
    for i in range( len( source ) ):
        table[ source[ i ] ] = target[ i ]

    alphabet = set( 'abcdefghijklmnopqrstuvwxyz ' )
    sourceSet = set( source )

    missingSource = alphabet - sourceSet
    if missingSource:
        assert len( missingSource ) == 1

        targetSet = set( target )
        missingTarget = alphabet - targetSet

        table[ next( iter( missingSource ) ) ] = next( iter( missingTarget ) )

        assert len( table ) == len( alphabet )

    return table


def main( input ):
    source = 'ejp mysljylc kd kxveddknmc re jsicpdrysi' + \
            'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd' + \
            'de kr kd eoya kw aej tysr re ujdr lkgc jv' + \
            'qee'
    target = 'our language is impossible to understand' + \
            'there are twenty six factorial possibilities' + \
            'so it is okay if you want to just give up' + \
            'zoo'

    assert len( source ) == len( target )

    table = buildTable( source, target )

    count = int( input.readline() )
    for index in range( 1, count + 1 ):
        source = input.readline().replace( '\n', '' )
        target = source.translate( str.maketrans( table ) )
        print( 'Case #{}: {}'.format( index, target ) )


main( sys.stdin )
