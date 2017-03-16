from math import log , exp

def solve( B , ps ) :
    logP = 0.0
    best = B + 2.0
    for cor in range( len( ps ) + 1 ) :
        pret = len( ps ) + B + 1.0 - 2.0 * cor + ( B + 1.0 ) * ( 1.0 - exp( logP ) )
        if ( pret < best ) :
            best = pret
        if ( ( cor >= len( ps ) ) or ( ps[ cor ] == 0 ) ) :
            break
        logP += log( ps[ cor ] )
    return best

def main():
    fIn = open( r'C:\\gjam\\pass\\in.txt' )
    fOut = open( r'C:\\gjam\\pass\\out.txt' , 'w' )
    nTasks = int( fIn.readline() )
    for task in range( 1 , nTasks + 1 ) :
        A , B = [ float( x ) for x in fIn.readline().split() ]
        ps = [ float( x ) for x in fIn.readline().split() ]
        fOut.write( 'Case #' + str( task ) + ': ' + str( solve( B , ps ) ) + '\n' )


if __name__ == '__main__':
    main()
