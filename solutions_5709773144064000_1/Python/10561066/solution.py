# Python 3.4

# Codejam, 2014, Round Q, Problem B

import itertools
import sys

def main() :
    TT = int( input() )
    for case in range( 1 , 1+TT ) :
        CC , FF , XX = ( float( x ) for x in input().split() )
        cumulative = 0.0
        numerator = XX
        denominator = 2.0
        previous_time = numerator / denominator
        for nn in itertools.count() :
            cumulative += CC / ( 2 + nn * FF )
            numerator += CC + FF * cumulative
            denominator += FF
            time = numerator / denominator
            if time > previous_time :
                break
            #end-if
            previous_time = time
        #end-for
        print( "Case #{case}: {answer}".format( case=case , answer=previous_time ) )
    #end-for    
    return 0 # EXIT_SUCCESS
#end-def-main


if __name__ == "__main__" :
    sys.exit( main() )
    #end-if


