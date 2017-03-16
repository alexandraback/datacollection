'''Online Round 1C Problem A. '''

import sys


CON = { 'a', 'e', 'i', 'o', 'u' }

def solve( word, n ):
    sub = ''
    subIndex = None
    subCount = 0
    comps = []
    length = len( word )

    for index in range( length + 1 ):
        letter = word[ index ] if index < length else None
        if letter not in CON and letter is not None:
            if subIndex is None:
                subIndex = index
            subCount += 1
            sub += letter
        else:
            if subCount >= n:
                for i in range( subCount - n + 1 ):
                    comps.append( [ word[ subIndex + i : subIndex + i + n ], subIndex + i, n ] )

            sub = ''
            subIndex = None
            subCount = 0

    value = 0
    for i in range( len( comps ) ):
        sub, index, count = comps[ i ]

        if i > 0:
            pre = index - comps[ i - 1][ 1 ]
        else:
            pre = index + 1

        post = ( length - index - count + 1 )

        value += pre * post

    return value


def main( input ):
    count = int( input.readline() )
    for index in range( 1, count + 1 ):
        word, n = input.readline().split()

        result = solve( word, int( n ) )
        print( 'Case #{}: {}'.format( index, result ) )


#main( open( 'D:/Works/nt-kookii/sources/python/natuum/GCJ 2013/input.txt' ) )
main( sys.stdin )
